/* cpppr400.eq
  
   scips.com

   March 28, 2003

   crime worksheet
*/
                                                           
where cppcrime1:policy_no = sfpprint9:policy_no and
      cppcrime1:pol_year = sfpprint9:pol_year and
      cppcrime1:end_sequence = sfpprint9:end_sequence and
      cppcrime1:prem_no = sfpprint9:prem_no and
      cppcrime1:build_no = sfpprint9:build_no and
      cppcrime1:county <> 0 
list
/domain="cppcrime1"
/nobanner
/nopageheadings
/nototals
/noduplicates               
/noheadings

sorted by cppcrime1:policy_no

end of cppcrime1:policy_no
""/newline=2
"CRIME"/column=35/newline=2
sfpprint9:prem_no/heading="Location"
sfpprint9:build_no/heading="Building"
                                   
""/newline
cppcrime1:state/heading="State"
trun(sfsstate:description)
cppcrime1:county/heading="County"/column=40
trun(sfsstate_alias:description)/newline=2

end of report 
""/newline=2
