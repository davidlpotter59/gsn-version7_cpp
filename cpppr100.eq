/* cpppr100.eq
  
   scips.com

   March 28, 2003

   property worksheet
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
                
list
/domain="sfpprint5"
/nobanner
/nopageheadings
/nototals
/noduplicates               
/noheadings

sfscompany:name[1]/newline=2/column=25

sfpname:policy_no/heading="policy No"
sfpname:pol_year/noheading
sfpname:end_sequence/noheading
sfsagent:name[1] + " - " + str(sfpname:agent_no)/heading="Agent"/newline=2
/column=40

if i_rev_name_1 <> "" then
    {
    i_rev_name_1/newline
    }
if i_rev_Name_2 <> "" then
    {
    i_rev_name_2/newline
    }
if i_rev_name_3 <> "" then
    {
    i_rev_name_3/newline
    }
if sfpname:address[1] <> "" then
    {
    sfpname:address[1]/newline
    }
if sfpname:address[2] <> "" then
    {
    sfpname:address[2]/newline
    }
if sfpname:address[3] <> "" then
    {
    sfpname:address[3]/newline
    }
if sfpname:city <> "" then
    {
    sfpname:city + "," + " " + sfpname:str_state + " " + str_zipcode[1,5] + 
"-" + str_zipcode[6,9]/newline
    }
                              
""/newline
sfpname:eff_date/heading="Effective Date"
sfpname:exp_date/heading="Expiration Date"/newline=2/column=40

"Form of Business:"
sfpmaster:form_of_business
switch(sfpmaster:form_of_business)
  case "C" : "Corporation"
  case "I" : "Individual"
  case "J" : "Joint Venture"
  case "O" : "Organization"
  case "P" : "Partnership"
  default  : sfpmaster:fob_description
"Special Commission:"/column=40
sfpname:spec_comm_rate/newline
"Package Policy:" 
switch(sfpname:package)
  case 1  : "Y"
  default : "N"
"Previous Policy:"/column=40
sfpname:previous_policy_no/newline=2
