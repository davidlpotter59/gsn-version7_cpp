/* cpppr400a.eq
  
   scips.com

   March 28, 2003

   crime worksheet
*/
                                                           
where cppcrime1:policy_no = sfpprint9:policy_no and
      cppcrime1:pol_year = sfpprint9:pol_year and
      cppcrime1:end_sequence = sfpprint9:end_sequence and
      cppcrime1:prem_no = sfpprint9:prem_no and
      cppcrime1:build_no = sfpprint9:build_no 
list
/domain="cppcrime1"
/nobanner
/nopageheadings
/nototals
/duplicates               
/noheadings
     
cppcrime1:code
cppcrime1:description
cppcrime1:premium/column=59

sorted by cppcrime1:policy_no
          cppcrime1:pol_year
          cppcrime1:end_sequence 
          cppcrime1:prem_no
          cppcrime1:build_no

top of page
""/newline=2
                           
end of report
""/newline=2

end of cppcrime1:policy_no              
""/newline=2
"Crime Total:"/column=1
total[cppcrime1:premium]/column=61/mask="ZZZ,ZZZ.99-"
