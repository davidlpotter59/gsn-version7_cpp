/* cpppr500c.eq
  
   scips.com

   March 28, 2003

   property worksheet - totals
*/                                
                              
define unsigned ascii number l_total_1 = parameter
                             l_total_2 = parameter
                             l_total_3 = parameter
                             l_total_4 = parameter
                           
define unsigned ascii number l_final_total = l_total_1 + l_total_2 +
                                             l_total_4

where cppliability:policy_no = sfpprint5:policy_no and
      cppliability:pol_year = sfpprint5:pol_year and
      cppliability:end_sequence = sfpprint5:end_sequence 

list
/domain="cppliability"
/nobanner
/nopageheadings
/nototals
/duplicates               
/noheadings
   
end of report
""/newline
"Total Premises/Operations:"
l_total_1/mask="ZZ,ZZZ,ZZZ.99"/newline/column=58
"Total Products/Completed Ops:"
l_total_2/mask="ZZ,ZZZ,ZZZ.99"/column=58/newline
"Independent Contractor:      "
l_total_4/mask="ZZ,ZZZ,ZZZ.99"/column=58/newline
           
""/newline
"Liability Total:"
l_final_total/mask="ZZ,ZZZ,ZZZ.99"/newline/column=58
"Minimum Premium:"
l_total_3/mask="ZZ,ZZZ,ZZZ.99"/newline/column=58

top of report
""/newline
