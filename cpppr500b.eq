/* cpppr500b.eq
  
   scips.com

   March 28, 2003

   property worksheet - totals
*/                                
                              
where sfpend:policy_no = sfpprint5:policy_no and
      sfpend:pol_year = sfpprint5:pol_year and
      sfpend:end_sequence = sfpprint5:end_sequence and
      sfpend:prem_no = sfpprint5:prem_no and
      sfpend:build_no = sfpprint5:build_no 
list
/domain="sfpend"
/nobanner
/nopageheadings
/nototals
/duplicates               
/noheadings
                       
if sfpend:lob_end_code = "L" then
    {              
    sfpend:form_edition
    sfpend:description[1,30]
    if sfpend:manual_premium <> 0 then
        sfpend:manual_premium/column=58
    else
        sfpend:premium
    }

   
sorted by sfpend:prem_no
          sfpend:build_no

top of page
"Form Edition"/column=5
"Description"/column=30
"Premium"/column=60/newline=2
   

top of report
""/newline
