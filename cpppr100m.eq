/* cpppr100m.eq
  
   scips.com

   March 28, 2003

   property worksheet - earthquake
*/

define unsigned ascii number l_limit_1 = cppgeneral:limit[1] divide 100
                             l_limit_2 = cppgeneral:limit[2] divide 100

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
if cppgeneral:earthquake = 1 then
    {
    "Earthquake:"       
    if cppgeneral:limit[1] <> 0 then
        {
        cppgeneral:base_rate[5]/column=33
        if cppgeneral:new_rate[5] <> 0 then
            cppgeneral:new_rate[5] 
        }
    if cppgeneral:limit[2] <> 0 then
        {
        cppgeneral:base_rate[11]/column=63
        if cppgeneral:new_rate[11] <> 0 then
            cppgeneral:new_Rate[11]
        }    

        ""/newline            
        "Co Deviation:"/column=1
        if cppgeneral:limit[1] <> 0 then
            {
            if cppgeneral:company_deviation[1] <> 1 and
               cpsdefault:deviation_number_not_factor = 1 then
                {
                (1 + (cppgeneral:companY_DEVIATION[1] * 0.01))/column=29
                }
            else 
                {
                cppgeneral:company_deviation[1]/column=32
                }
            }                              
        if cppgeneral:limit[2] <> 0 then
            {
            if cppgeneral:company_deviation[1] <> 1 and
               cpsdefault:deviation_number_not_factor = 1 then
                {
                (1 + (cppgeneral:companY_DEVIATION[1] * 0.01))/column=59
                }
            else 
                {
                cppgeneral:company_deviation[1]/column=62
                }
            }
                                            
    ""/newline
    "Per 100:"
    if cppgeneral:limit[1] <> 0 then
        {
        l_limit_1/column=26/mask="ZZ,ZZZ,ZZZ.999"
        }      

    if cppgeneral:limit[2] <> 0 then
        {
        l_limit_2/column=56/mask="ZZ,ZZZ,ZZZ.999"
        }                                        

    if sfscompany:boiler_rating = 2 then 
        {                                        
        ""/newline        
        "Rating Territory Factor:"/column=1
        if cppgeneral:limit[1] <> 0 then      
            {
            cppgeneral:rating_territory_factor/column=33
            }
        if cppgeneral:limit[2] <> 0 then      
            {
            cppgeneral:rating_territory_factor/column=63
            }
        }

        ""/newline    
        "PMA Factor:"
        if cppgeneral:limit[1] <> 0 then
            {
            if cppgeneral:package_mod[1] <> 1 and
               cpsdefault:deviation_number_not_factor = 1 then
                {
                (1 + (cppgeneral:package_mod[1] * 0.01))/column=29
                }
            else 
                {
                cppgeneral:package_mod[1]/column=32
                }
            }
        if cppgeneral:limit[2] <> 0 then
            {
            if cppgeneral:package_mod[1] <> 1 and
               cpsdefault:deviation_number_not_factor = 1 then
                {
                (1 + (cppgeneral:package_mod[1] * 0.01))/column=59
                }
            else 
                {
                cppgeneral:package_mod[1]/column=62
                } 
            }
                                             
    ""/newline=2
    "Total Earthquake:"
    if cppgeneral:limit[1] <> 0 then
        {                                 
        cppgeneral:premium[5]/column=27
        }
    if cppgeneral:limit[2] <> 0 then
        {
        cppgeneral:premium[11]/column=57
        }                      
    ""/newline=2
    }

sorted by cppgeneral:prem_no
          cppgeneral:build_no
