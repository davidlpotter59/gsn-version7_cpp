/* cpppr500d.eq
  
   scips.com

   March 28, 2003

   liability worksheet - misc
*/                                
                              
define file alt_sfpmisc = access sfpmisc, set
sfpmisc:policy_no = sfpmaster:policy_no, 
sfpmisc:pol_year = sfpmaster:pol_year,
sfpmisc:end_sequence= sfpmaster:end_sequence, generic

where sfpmaster:policy_no = sfpprint5:policy_no and
      sfpmaster:pol_year = sfpprint5:pol_year and
      sfpmaster:end_sequence = sfpprint5:end_sequence  
list
/domain="sfpmaster"
/nobanner
/nopageheadings
/nototals
/duplicates               
/noheadings
                         
"MISCELLANEOUS"/column=35/newline=2
"Description"/column=5
"Premium"/column=62/newline=2

followed by
                                 
if alt_sfpmisc:policy_no = sfpmaster:policy_no and
   alt_sfpmisc:pol_Year = sfpmaster:pol_year and 
   alt_sfpmisc:end_sequence = sfpmaster:end_sequence then
    {
    if alt_sfpmisc:lob_end_code = "L" then
        {
        trun(alt_sfpmisc:description[1,30])
        alt_sfpmisc:premium/column=58
        }
    }

top of report
""/newline
