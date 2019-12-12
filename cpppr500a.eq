/* cpppr500a.eq
  
   scips.com

   March 28, 2003

   liability worksheet
*/
                                                           
define string l_exposure_base_1 = cppliability:exposure_base[1]
              l_exposure_base_2 = cppliability:exposure_base[2]
                                 
define unsigned ascii number l_form[2] = cppliablimits:form 
                             l_line_of_business[4]=0008

define file alt_cpsliabform = access cpsliabform, set
cpsliabform:company_id = sfpname:company_id,
cpsliabform:state = cppliability:state,
cpsliabform:line_of_business= l_line_of_business, 
cpsliabform:liability_form= l_form, generic

define file alt_cpsliabexpbase = access cpsliabexpbase, set
cpsliabexpbase:company_id= sfpname:company_id,
cpsliabexpbase:state = cppliability:state,
cpsliabexpbase:line_of_business= l_line_of_business,
cpsliabexpbase:exposure_base= l_exposure_base_1, generic

define file alt1_cpsliabexpbase = access cpsliabexpbase, set
cpsliabexpbase:company_id= sfpname:company_id,
cpsliabexpbase:state = cppliability:state,
cpsliabexpbase:line_of_business= l_line_of_business,
cpsliabexpbase:exposure_base= l_exposure_base_2, generic
                     
define file cpsclassgrp_alt = access cpsclassgrp, set
cpsclassgrp:company_id= sfpname:company_id,
cpsclassgrp:state = cppliability:state,
cpsclassgrp:line_of_business= l_line_of_business,
cpsclassgrp:group_no = cppliability:group_no,
cpsclassgrp:sub_group= cppliability:sub_group, generic

where cppliability:policy_no = sfpprint9:policy_no and
      cppliability:pol_year = sfpprint9:pol_year and
      cppliability:end_sequence = sfpprint9:end_sequence and
      cppliability:prem_no = sfpprint9:prem_no and
      cppliability:build_no = sfpprint9:build_no
list
/domain="cppliability"
/nobanner
/nopageheadings
/nototals
/noduplicates               
/noheadings

""/newline=2
cppliability:prem_no/heading="Location"
cppliability:build_no/heading="Building"
sfplocation:address/newline/column=40
if sfplocation:address1[1] <> "" then
    {
    sfplocation:address1[1]/newline/column=40
    }
if sfplocation:address1[2] <> "" then
    {
    sfplocation:address1[2]/newline/column=40
    }
if sfplocation:address1[3] <> "" then
    {
    sfplocation:address1[3]/newline/column=40 
    }
if sfplocation:city <> "" then
    {
    sfplocation:city + ", " + sfplocation:str_state + " " + 
    sfplocation:str_zipcode[1,5] + "-" + 
    sfplocation:str_zipcode[6,9]/newline/column=40
    }
                                   
""/newline        
"Business Description:"
trun(cppliability:business_description[1]) + " " + 
trun(cppliability:business_description[2])/newline=2
 
cppliability:state/heading="State"
trun(sfsstate:description)
cppliability:county/heading="County"/column=40
trun(sfsstate_alias:description)/newline
cppliablimits:form/heading="Form"/column=1
trun(alt_cpsliabform:description)
cppliability:limits_table/heading="Limits Table"/column=40/newline=2
                                   
"Group:"
cppliability:group_no/column=15
cpsclassgrp_alt:description/newline  
cppliability:class_code/heading="Class Code"/mask="9999"
if cppliability:class_description <> "" then
    cppliability:class_description
else
    cpsclass:alpha_look/newline=2/toggle

"Motel With Pool:"
switch(cppliability:motel_with_pool)
  case 1  : "Yes"
  default : "No"
"Seasonal No Days:"/column=40
cppliability:seasonal_no_days/newline=2

"Premises/Operations"/newline
"Exposure Base:"/column=5
trun(alt_cpsliabexpbase:description) + " Per - " + str(cppliability:rates_per[1])/newline 
"Exposure:"/column=5
cppliability:exposure[1]/newline=2/mask="ZZ,ZZZ,ZZ9"

"Base Rate:"/column=5
cppliability:base_rate[1]/newline/column=37
"Territory Factor:"/column=5
cppliability:territory_factor/newline/column=38
if cppliability:mcl030_discount <> 1.00 then
    {
    "MCL030 Discount:"/column=5
    cppliability:mcl030_discount/newline/column=39
    }
"Increased Limits Factor:"/column=5
cppliability:increase_limits_factor[1]/newline/column=38
if cppliability:deductible_factor[1] <> 0 then
    {
    "Deductible Factor:"/column=5
    cppliability:deductible_factor[1]/newline/column=38
    }
if cppliability:aggregate_surcharge[1] <> 1.00 then
    {
    "Aggregate Surcharge:"/column=5
    cppliability:aggregate_surcharge[1]/newline/column=37
    }
if cppliability:medical_payment_surcharge <> 0 then
    {
    "Medical Payment:"/column=5
    cppliability:medical_payment_surcharge/column=38/newline
    }
    "Co Deviation:"/column=5
    if cppdeviation:company_deviation <> 1 and
       cpsdefault:deviation_number_not_factor = 1 then
        {
        (1 + (cppdeviation:company_deviation * 0.01))/column=34/newline
        }
    else 
        { 
        cppdeviation:company_deviation/newline/column=37
        }
    "PMA Factor:"/column=5
    if cppdeviation:package_mod <> 1 and
       cpsdefault:deviation_number_not_factor = 1 then
        {
        (1 + (cppdeviation:package_mod * 0.01))/column=34/newline
        } 
    else 
        { 
        cppdeviation:package_mod/newline/column=37
        }

    if sfscompany:boiler_rating = 2 then 
        {                                                
        "Rating Territory Factor:"/column=5
        cppliability:rating_territory_factor/column=38
        ""/newline
        }                                             

"Per:"/column=5
cppliability:exposure[1] divide cppliability:rates_per[1]/mask="ZZ,ZZZ.999"
/column=35

""/newline=2
if cppliability:fire_legal_premium <> 0 then
    {
    "Fire Legal Premium:"/column=5
    cppliability:fire_legal_premium/column=32/newline/mask="ZZ,ZZZ,ZZZ.99"
    "Fire Legal Property Rate:"/column=5
    cppliablimits:fire_legal_property_rate/column=38/newline 
    }

if cppliability:escalators_premium[1] <> 0 then
    {
    "Office Escalators:"/column=5
    cppliability:escalators_premium[1]/column=32/newline/mask="ZZ,ZZZ,ZZZ.99"
    }
if cppliability:escalators_premium[2] <> 0 then
    {
    "All Other Escalators:"/column=5
    cppliability:escalators_premium[2]/column=32/newline/mask="ZZ,ZZZ,ZZZ.99"
    }
if cppliability:mechanical_devices_premium <> 0 then
    {
    "Mechanical Devices:"/column=5
    cppliability:mechanical_devices_premium/column=32/newline/mask="ZZ,ZZZ,ZZZ.99"
    }
if cppliability:ski_lifts_premium <> 0 then
    {
    "Ski Lifts/Runs/Tows:"/column=5
    cppliability:ski_lifts_premium/column=32/newline/mask="ZZ,ZZZ,ZZZ.99"
    }
if cppliability:pools_beaches_premium[1] <> 0 then
    {
    "Pools/Beachs - Campgrounds:"/column=5
    cppliability:pools_beaches_premium[1]/column=32/newline/mask="ZZ,ZZZ,ZZZ.99"
    }
if cppliability:pools_beaches_premium[2] <> 0 then
    {
    "Pools/Beachs - Other:"/column=5
    cppliability:pools_beaches_premium[2]/column=32/newline/mask="ZZ,ZZZ,ZZZ.99"
    }           
                                           
""/newline
"Total Premises/Operations:"/column=5
cppliability:prem[1]/newline=2

"Products/Completed Operations"/newline
"Exposure Base:"/column=5
trun(alt1_cpsliabexpbase:description) + " Per - " + str(cppliability:rates_per[2])/newline 
"Exposure:"/column=5
cppliability:exposure[2]/newline=2/mask="ZZ,ZZZ,ZZ9"

"Base Rate:"/column=5
cppliability:base_rate[2]/column=37
if cppliability:products_flat = 1 then
    {
    "Flat"
    }
""/newline 
"Increased Limits Factor:"/column=5
cppliability:increase_limits_factor[2]/newline/column=38
if cppliability:deductible_factor[2] <> 0 then
    {
    "Deductible Factor:"/column=5
    cppliability:deductible_factor[2]/newline/column=38
    }
if sfscompany:special_territory_rating <> 1 then
    {
    "Co Deviation:"/column=5
    if cppdeviation:company_deviation <> 1 and
       cpsdefault:deviation_number_not_factor = 1 then
        {
        (1 + (cppdeviation:company_deviation * 0.01))/column=34/newline
        }
    else 
        { 
        cppdeviation:company_deviation/newline/column=37
        }
    }
    "PMA Factor:"/column=5
    if cppdeviation:package_mod <> 1 and
       cpsdefault:deviation_number_not_factor = 1 then
        {
        (1 + (cppdeviation:package_mod * 0.01))/column=34/newline
        }
    else 
        { 
        cppdeviation:package_mod/newline/column=37
        }

    if sfscompany:boiler_rating = 2 then 
        {                                                
        "Rating Territory Factor:"/column=5
        cppliability:rating_territory_factor/column=38                                    
        ""/newline
        }

"Territory Factor:"/column=5
"1.00"/newline/column=40
"Per:"/column=5
cppliability:exposure[2] divide cppliability:rates_per[2]/mask="ZZ,ZZZ.999"
/column=35

""/newline=2
"Total Products/Completed:"/column=5
cppliability:prem[2]/newline=2/column=32          
             
"Independent Contractor:  "/column=1
cppliability:independent_contractor_premium/mask="ZZ,ZZZ,ZZZ.99"/newline
/column=32
 
sorted by cppliability:prem_no
          cppliability:build_no
