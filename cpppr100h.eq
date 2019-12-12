/* cpppr100h.eq
  
   scips.com

   March 28, 2003

   property worksheet - totals
*/                                
                              
define file alt_sfpend = access sfpend, set
sfpend:policy_no = cppgeneral:policy_no, 
sfpend:pol_year = cppgeneral:pol_year,
sfpend:end_sequence= cppgeneral:end_sequence, generic

define file alt_sfpmisc = access sfpmisc, set
sfpmisc:policy_no = cppgeneral:policy_no, 
sfpmisc:pol_year = cppgeneral:pol_year,
sfpmisc:end_sequence= cppgeneral:end_sequence, generic

define file alt_cppbusiness = access cppbusiness, set
cppbusiness:policy_no= cppgeneral:policy_no,   
cppbusiness:pol_year = cppgeneral:pol_year,
cppbusiness:end_sequence= cppgeneral:end_sequence,
cppbusiness:prem_no = cppgeneral:prem_no,
cppbusiness:build_no = cppgeneral:build_no, generic

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
/duplicates               
/noheadings
                         
"OPTIONAL ENDORSEMENTS"/column=35/newline=2
"Form Edition"/column=5
"Description"/column=30   
"Premium"/column=62/newline=2

followed by
                                 
if alt_sfpend:policy_no = cppgeneral:policy_no and
   alt_sfpend:pol_year = cppgeneral:pol_year and
   alt_sfpend:end_sequence = cppgeneral:end_sequence and
   alt_sfpend:prem_no = cppgeneral:prem_no and
   alt_sfpend:build_no = cppgeneral:build_no then
    {
    if alt_sfpend:lob_end_code = "P" or
       alt_sfpend:lob_end_code = "B" then
        {
        alt_sfpend:form_edition
        trun(alt_sfpend:description[1,30])/column=20
        if alt_sfpend:premium <> 0 then
            alt_sfpend:premium/column=58
        if alt_sfpend:manual_premium <> 0 then
            alt_sfpend:manual_premium/column=58
        }
    }

sorted by cppgeneral:prem_no
          cppgeneral:build_no

top of report
""/newline
