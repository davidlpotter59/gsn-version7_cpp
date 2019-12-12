/* cpppr500.eq
  
   scips.com

   March 28, 2003

   liability worksheet
*/


where cppliability:policy_no = sfpprint9:policy_no and
      cppliability:pol_year = sfpprint9:pol_year and
      cppliability:end_sequence = sfpprint9:end_sequence and
      cppliability:prem_no = sfpprint9:prem_no and
      cppliability:build_no = sfpprint9:build_no and
      cppliability:class_code = sfpprint9:class_code 
list
/domain="cppliability"
/nobanner
/nopageheadings
/nototals
/noduplicates               
/noheadings 

""/newline=2
"LIABILITY"/column=35/newline=2
"Occurrence:"/column=1
cppliablimits:occurrence/column=21/mask="ZZ,ZZZ,ZZ9"
"Medical Payments"/column=40
cppliablimits:medical_payments/newline/column=69/mask="ZZ,ZZZ,ZZ9"
"General Aggregate:"/column=1
cppliablimits:general_aggregate/column=21/mask="ZZ,ZZZ,ZZ9"
"Fire Legal:"/column=40
cppliablimits:fire_legal/newline/column=69/mask="ZZ,ZZZ,ZZ9"
"Products Aggregate:"/column=1
cppliablimits:products/mask="ZZ,ZZZ,ZZ9" 
"Advertising Personal Injury:"/column=40
cppliablimits:advertising_personal_injury/mask="ZZ,ZZZ,ZZ9" 
""/newline=2
   
sorted by cppliability:prem_no
          cppliability:build_no
