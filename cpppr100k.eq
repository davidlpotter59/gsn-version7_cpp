/* cpppr100k.eq
  
   scips.com

   March 28, 2003

   property worksheet - totals
*/                                
                              
define signed ascii number l_total_1 = parameter
                           l_total_2 = parameter
                           l_total_3 = parameter
                           l_total_4 = parameter

define file alt_sfpend = access sfpend, set
sfpend:policy_no = cppgeneral:policy_no, 
sfpend:pol_year = cppgeneral:pol_year ,
sfpend:end_sequence= cppgeneral:end_sequence, generic

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

""/newline
"Total Building:"
l_total_1/mask="ZZ,ZZZ,ZZZ.99-"/newline/column=57
"Total Contents:"
l_total_2/mask="ZZ,ZZZ,ZZZ.99-"/column=57/newline
"Total Optional:"
l_total_3/mask="ZZ,ZZZ,ZZZ.99-"/column=57/newline
           
""/newline
"Property Total:       "
l_total_1 + l_total_2 + l_total_3/mask="ZZ,ZZZ,ZZZ.99-"/newline/column=57
"Business Income Total:"
l_total_4/mask="ZZ,ZZZ,ZZZ.99-"/newline/column=57
   
sorted by cppgeneral:prem_no
          cppgeneral:build_no

top of report
""/newline
