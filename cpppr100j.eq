/* cpppr100j.eq
  
   scips.com

   December 2, 2003

   policy wide endorsements
*/                                
                              
where sfpend:policy_no = sfpprint5:policy_no and
      sfpend:pol_year = sfpprint5:pol_year and
      sfpend:end_sequence = sfpprint5:end_sequence and
      sfpend:prem_no = 0 and
      sfpend:build_no = 0
list
/domain="sfpend"
/nobanner
/nopageheadings
/nototals
/duplicates               
/noheadings

followed by
       
box
sfpend:form_edition
sfpend:description[1,30]/column=20
if sfpend:manual_premium <> 0 then
    sfpend:manual_premium/column=58
else
    sfpend:premium
end box
   
sorted by sfpend:prem_no
          sfpend:build_no

top of page
"Form Edition"/column=5
"Description"/column=30
"Premium"/column=64/newline

top of report
""/newline
