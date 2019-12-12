/* cpppr100g.eq
  
   scips.com

   March 28, 2003

   property worksheet - totals
*/                                

define file alt_sfpend = access sfpend, set
sfpend:policy_no = cppgeneral:policy_no,
sfpend:pol_year = cppgeneral:pol_year,
sfpend:end_sequence= cppgeneral:end_sequence,  
sfpend:prem_no = cppgeneral:prem_no,
sfpend:build_no = cppgeneral:build_no, generic

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

""/newline=2
if cppproperty:boiler = 1 then
    {
    "Total Boiler/Machinery:"
    if cppgeneral:limit[1] <> 0 then
        {
        cppproperty:boiler_premium[1]/column=27 
        }
    if cppgeneral:limit[2] <> 0 then
        {
        cppproperty:boiler_premium[2]/column=57
        }
    }                                                

""/newline=2                         
"Total Premium:"          
if cppgeneral:limit[1] <> 0 then
    {
    cppgeneral:premium[1] + cppgeneral:premium[2] + 
    cppgeneral:premium[3] + cppgeneral:premium[4] +
    cppgeneral:premium[5] + cppgeneral:premium[6] +
    cppproperty:boiler_premium[1]/column=27/mask="ZZ,ZZZ,ZZZ.99"

    }
if cppgeneral:limit[2] <> 0 then
    {
    cppgeneral:premium[7] + cppgeneral:premium[8] +
    cppgeneral:premium[9] + cppgeneral:premium[10] +
    cppgeneral:premium[11] + cppgeneral:premium[12] +
    cppproperty:boiler_premium[2]/column=57/mask="ZZ,ZZZ,ZZZ.99"
    }

""/newline=2
"A/R:"/column=1
cppproperty:ar_limit/column=21/mask="$$$,$$$"
cppproperty:ar_prem/column=26/mask="ZZZ,ZZZ.99-"
"Debris:"/column=37
cppproperty:debris_removal/column=57/mask="$$$,$$$"
cppproperty:debris_removal_prem/column=65/mask="ZZZ,ZZZ.99-"/newline

"Peak Season:"
if cppproperty:peak_season_factor <> 0 then
    cppproperty:peak_season_factor/align=cppproperty:ar_limit
cppproperty:peak_season_prem/align=cppproperty:ar_prem/mask="ZZZ,ZZZ.99-" 
"Off Prem Other Loc:"/column=37
cppproperty:off_prem_other_location/align=cppproperty:debris_removal/mask=
"$$$,$$$"
cppproperty:off_prem_other_loc_prem/align=cppproperty:debris_removal_prem
/mask="ZZZ,ZZZ.99-"/newline  

"Glass:"/column=1
cppproperty:glass_limit/align=cppproperty:ar_limit/mask="$$$,$$$"
cppproperty:glass_prem/align=cppproperty:ar_prem/mask="ZZZ,ZZZ.99-"

"Off Prem In Transit:"/column=37
cppproperty:off_prem_in_transit/mask="$$$,$$$"/align=cppproperty:debris_removal
cppproperty:off_prem_in_transit_prem/mask="ZZZ,ZZZ.99-"/align=
cppproperty:debris_removal_prem/newline

"Signs Not Attached:"/column=1
cppproperty:signs_not_attached/mask="$$$,$$$"/align=cppproperty:ar_limit
cppproperty:signs_not_attached_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:ar_prem

"Outdoor Property:"/column=37
cppproperty:outdoor_property/mask="$$$,$$$"/align=cppproperty:debris_removal
cppproperty:outdoor_property_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:debris_removal_prem/newline

"Signs Attached:"/column=1
cppproperty:signs_attached/mask="$$$,$$$"/align=cppproperty:ar_limit
cppproperty:signs_attached_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:ar_prem
    
"Personal Effects:"/column=37
cppproperty:personal_effects/mask="$$$,$$$"/align=cppproperty:debris_removal
cppproperty:personal_effects_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:debris_removal_prem/newline

"Building Code:"/column=1
cppproperty:building_code_percent/align=cppproperty:ar_limit
cppproperty:building_code_prem/align=cppproperty:ar_prem/mask="ZZZ,ZZZ.99-"

"Property Others:"/column=37
cppproperty:personal_property_of_others/mask="$$$,$$$"/align=cppproperty:debris_removal 
cppproperty:personal_property_other_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:debris_removal_prem/newline

"Utility:"/column=1
cppproperty:loss_utility/mask="$$$,$$$"/align=cppproperty:ar_limit
cppproperty:loss_utility_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:ar_prem

"Valuable Papers:"/column=37
cppproperty:valuable_papers/mask="$$$,$$$"/align=cppproperty:debris_removal
cppproperty:valuable_papers_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:debris_removal_prem/newline 

"Mechanical:"/column=1
cppproperty:mechanical_breakdown/mask="$$$,$$$"/align=cppproperty:ar_limit
cppproperty:mechanical_breakdown_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:ar_prem

"Precious Metals:"/column=37
cppproperty:precious_metals/mask="$$$,$$$"/align=cppproperty:debris_removal
cppproperty:precious_metals_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:debris_removal_prem/newline 

"Water Backup:"/column=1
if cppproperty:water_backup <> 0 then
    cppproperty:water_backup/mask="$$$,$$$"/align=cppproperty:ar_limit
cppproperty:water_backup_premium/mask="ZZZ,ZZZ.99-"/align=cppproperty:ar_prem

"Loss Assessment:"/column=37
cppproperty:loss_assessment/mask="$$$,$$$"/align=cppproperty:debris_removal
cppproperty:loss_assessment_prem/mask="ZZZ,ZZZ.99-"/align=cppproperty:debris_removal_prem/newline 

"MCP505 Option:"/column=1                                                     
switch(cppproperty:mcp505_option)
  case 1  : "Y"/mask="$$$,$$$"/align=cppproperty:ar_limit
  default : "N"
cppproperty:mcp505_premium/mask="ZZZ,ZZZ.99-"/align=cppproperty:ar_prem
/newline

sorted by cppgeneral:prem_no
          cppgeneral:build_no
