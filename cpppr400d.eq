/* cpppr400d.eq
  
   scips.com

   March 28, 2003

   crime worksheet
*/
                                                           
where cppcrime:policy_no = sfpprint9:policy_no and
      cppcrime:pol_year = sfpprint9:pol_year and
      cppcrime:end_sequence = sfpprint9:end_sequence and
      cppcrime:prem_no = sfpprint9:prem_no and
      cppcrime:build_no = sfpprint9:build_no and
      cppcrime:crime_form = "D"
list
/domain="cppcrime"
/nobanner
/nopageheadings
/nototals
/duplicates               
/noheadings

""/newline=2     
if cppcrime:crime_form one of "D" then
    {
    "Robbery and Safe Burglary"
    "Deductible:"
    cppcrime:deductible 
    "INSIDE LIMIT"/column=45
    "OUTSIDE LIMIT"/newline/column=65
    cppcrime:limit[1]/column=45
    cppcrime:limit[2]/column=65/newline=2

    "Vault Class:"
    cppcrime:safe_class/newline
    "Assignment #:"
    cppcrime:risk_rating[1]
    cppcrime:safe_charge/column=48/mask="Z999.99"
    "N/A"/column=72/newline
    "Territory:"
    cppcrime:county
    cppcrime:territory_factor/column=50/mask="Z9.99"
    "N/A"/column=72/newline
    "Messengers:"
    cppcrime:no_messengers 
    "Guards Per:"
    cppcrime:no_guards
    "N/A"/column=52
    cppcrime:guard_charge[1]/column=71/mask="9.99"/newline 

    "Watch Person Service:"
    cppcrime:no_watchpersons 
    cppcrime:watchperson_service 
    cppcrime:watchperson_factor/column=51/mask="9.99"
    "N/A"/column=72/newline   

    "No of Guard Service:"
    cppcrime:no_guards_service 
    cppcrime:guard_service_factor/mask="9.99"/column=51
    "N/A"/column=72/newline        

    "Adjusted Rate:"
    cppcrime:adjusted_rate[1]/column=47/mask="ZZZ9.999"
    "N/A"/column=72/newline            

    "Premium first 1000:"
    cppcrime:total_first_1000[1]/column=47
    cppcrime:total_first_1000[2]/column=67/newline

    "Deductible Factor:"
    cppcrime:deductible_factor/column=51/mask="9.99"
    cppcrime:deductible_factor/column=71/newline=2/mask="9.99" 

    "Total:"
    cppcrime:crime_total_1[1]/column=47
    cppcrime:crime_total_1[2]/column=67/newline=2

    "Total Premium:"
    cppcrime:crime_total[1]/column=47
    cppcrime:crime_total[2]/column=67/newline=2

    "Premium:"
    cppcrime1:total_premium/column=19/newline/mask="ZZZ,ZZZ.99"

    "Co Deviation:"/column=1
    if cpsdefault:deviation_number_not_factor = 1 and
       cppcrime1:company_deviation not one of 1.00 then
        {
        (1 + (cppcrime1:company_deviation * 0.01))/column=19
        }
    else      
        {
        cppcrime1:company_deviation/column=22
        }
    ""/newline

    "PMA Factor:"/column=1
    if cpsdefault:deviation_number_not_factor = 1 and
       cppcrime1:package_mod not one of 1.00 then
        {
        (1 + (cppcrime1:package_mod * 0.01))/column=19
        }
    else 
        {
        cppcrime1:package_mod/column=22
        }
    ""/newline

    "Total Premium:"
    cppcrime1:premium/column=19/newline/mask="ZZZ,ZZZ.99"
    }    


sorted by cppcrime:prem_no
          cppcrime:build_no                                               
