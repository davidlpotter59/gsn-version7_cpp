/* cpppr100a.eq
  
   scips.com

   March 28, 2003

   property worksheet
*/


where cppgeneral:policy_no = sfpprint5:policy_no and
      cppgeneral:pol_year = sfpprint5:pol_year and
      cppgeneral:end_sequence = sfpprint5:end_sequence and 
      cppgeneral:prem_no = sfpprint5:prem_no and
      cppgeneral:build_no = sfpprint5:build_no
list
/domain="cppgeneral"
/nobanner
/nopageheadings
/nototals
/noduplicates               
/noheadings

""/newline=2   
"PROPERTY"/column=35/newline=2
cppgeneral:prem_no/heading="Location"
cppgeneral:build_no/heading="Building"
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
"Business Desc:"/column=1
trun(cppgeneral:business_desc[1]) + " " + trun(cppgeneral:business_desc[2])
/newline=2

cppgeneral:state/heading="State"
trun(sfsstate:description)
cppgeneral:county/heading="County"/column=40
trun(sfsstate_alias:description)/newline=2

"Rate Type:"/column=1
cppgeneral:rate_type/column=14
cpsratetype:description/newline
if cppgeneral:builders_risk = 1 then
    {
    "Builders Risk"/newline
    }
if cppgeneral:condo = 1 then
    {
    "Condo Association"/newline
    }
if cppgeneral:unit_owner = 1 then
    {
    "Condo Unit-Owner"/newline
    }
cppgeneral:construction/heading="Construction"
sfsconstruction:description
"Protection:"/column=40 
cppgeneral:protection/column=57/newline
"Form:"/column=1
cppgeneral:form/column=15
sfsform:description            
"Coinsurance:"/column=40
cppgeneral:coinsurance/newline/column=57
"Sprinklered:"
switch(cppgeneral:sprinklered)
  case 1  : "Yes"/column=15
  default : "No"          
"Replacement Cost:"/column=40
switch(cppgeneral:replacement_cost)
  case 1  : "Yes"
  default : "No"/newline                     
"Blanket:"/column=1
switch(cppgeneral:blanket)
  case 1  : "Yes"/column=15
  default : "No"                       
"Reinsurance:"/column=40
switch(cppgeneral:reins)
  case 1  : "Yes"
  default : "No"/column=58/newline=2

"Shopping Centers:"/column=1
switch(cppgeneral:shopping_centers)
  case 1  : "Yes"
  default : "No"
"Multiple Mercantiles:"/column=40
switch(cppgeneral:multiple_mercantiles)
  case 1  : "Yes"
  default : "No"/newline
"Mercantiles with Apts:"
switch(cppgeneral:mercantiles_with_apts)
  case 1  : "Yes"
  default : "No"/newline=2

cppgeneral:deductible/heading="Building Deductible"/mask="ZZ,ZZ9"
cppgeneral:contents_deductible/heading="Contents Deductible"/column=40/newline/mask="ZZ,ZZ9"
"Wind Deductible:"
cppgeneral:wind_deductible/mask="ZZ,ZZ9"/column=22
"Hurricane Deductible:"/column=40
cppgeneral1:hurricane_deductible/mask="ZZZZ9%"/column=58/newline
"Override Hurricane Deductible:"/column=40
cppgeneral1:override_hurricane_deductible/mask="ZZZZ9%"/column=67/newline=2

if cppgeneral:exclusions = 1 then
    {
    if cppexclusions:exclude_theft = 1 then
        "Theft Excluded"/newline
    if cppexclusions:exclude_vandalism = 1 then
        "Vandalism Excluded"/newline
    if cppexclusions:exclude_water_damage = 1 then
        "Water Excluded"/newline 
    if cppexclusions:exclude_wind_hail = 1 then
        "Wind Excluded"/newline
    }
                                   
"Group:"
cppgeneral:group_no/column=15
cpsclassgrp_alt:description/newline  
cppgeneral:class_code/heading="Class Code"/mask="9999"
cpstransitional:alpha_look/newline/toggle

sorted by cppgeneral:prem_no
          cppgeneral:build_no
