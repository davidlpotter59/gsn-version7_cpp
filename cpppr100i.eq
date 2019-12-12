/* cpppr100i.eq
  
   scips.com

   March 28, 2003

   final totals on worksheets
*/

define string i_name_1[50] = sfpname:name[1]
              I_FIRST_NAME_1 = Trun(I_NAME_1[(Pos(SFSCOMPANY:REVERSE_NAME_DELIMINATOR,I_NAME_1)+1),
                              Len(I_NAME_1)])
              I_LAST_NAME_1 = Trun(I_NAME_1[1,(Pos(SFSCOMPANY:REVERSE_NAME_DELIMINATOR,I_NAME_1)-1)])
              I_REV_NAME_1 = Trun(I_FIRST_NAME_1) + " " + Trun(I_LAST_NAME_1)
              i_name_2[50] = sfpname:name[2]
              I_FIRST_NAME_2 = Trun(I_NAME_2[(Pos(SFSCOMPANY:REVERSE_NAME_DELIMINATOR,I_NAME_2)+1),
                               Len(I_NAME_2)])
              I_LAST_NAME_2 = Trun(I_NAME_2[1,(Pos(SFSCOMPANY:REVERSE_NAME_DELIMINATOR,I_NAME_2)-1)])
              I_REV_NAME_2 = Trun(I_FIRST_NAME_2) + " " + Trun(I_LAST_NAME_2)
              i_name_3[50] = sfpname:name[3]
              I_FIRST_NAME_3 = Trun(I_NAME_3[(Pos(SFSCOMPANY:REVERSE_NAME_DELIMINATOR,I_NAME_3)+1),
                              Len(I_NAME_3)])
              I_LAST_NAME_3 = Trun(I_NAME_3[1,(Pos(SFSCOMPANY:REVERSE_NAME_DELIMINATOR,I_NAME_3)-1)])
              I_REV_NAME_3 = Trun(I_FIRST_NAME_3) + " " + Trun(I_LAST_NAME_3)

define file alt_cpsdefault = access cpsdefault, set
cpsdefault:company_id = sfpname:company_id,
cpsdefault:line_of_business = sfpname:line_of_business, generic
                
list
/domain="sfpprint5"
/nobanner
/nopageheadings
/nototals
/noduplicates               
/noheadings
                                    
""/newline
"IRPM:"
sfpmaster:total[8]/column=58/mask="ZZ,ZZZ,ZZZ.99-"/newline
"Total Premium:"
sfpmaster:total[18]/column=58/mask="ZZ,ZZZ,ZZZ.99"/newline
"Surcharge:"
sfpmaster:surcharge/column=58/mask="ZZ,ZZZ,ZZZ.99"/newline
if sfpreins:policy_no = sfpprint5:policy_no and
   sfpreins:pol_year = sfpprint5:pol_year and
   sfpreins:end_sequence = sfpprint5:end_sequence then
    {
    "Reinsurance:"
    sfpreins:reins_premium/column=58/mask="ZZ,ZZZ,ZZZ.99"
    }
    
