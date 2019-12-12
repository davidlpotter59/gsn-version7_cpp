/* cpppr100b.eq
  
   scips.com

   March 28, 2003

   property worksheet - fire
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
"BUILDING"/column=32
"CONTENTS"/column=62/newline
"Limit:"
cppgeneral:limit[1]/column=30
cppgeneral:limit[2]/column=60/newline=2
    
if cppgeneral:form >= 1 then
    {
    "Fire:"       
    if cppgeneral:limit[1] <> 0 then
        {
        cppgeneral:base_rate[1]/column=33
        if cppgeneral:new_rate[1] <> 0 then
            cppgeneral:new_rate[1]
        }
    if cppgeneral:limit[2] <> 0 then
        {
        cppgeneral:base_rate[7]/column=63
        if cppgeneral:new_rate[7] <> 0 then
            cppgeneral:new_rate[7]
        }    

    ""/newline
    if cppgeneral:file_no <> "" then
        {                           
        "Specific Rate Adjustment:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:specific_rate_adjustment[1]/column=34/mask="ZZ.999"
            if cppgeneral:specific_rate_minimum <> 0 and
               cppgeneral:specific_minimum[1] = 1 then
                {
                cppgeneral:specific_rate_minimum/column=42
                "M.F."
                }
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:specific_rate_adjustment[2]/column=64/mask="ZZ.999"
            if cppgeneral:specific_rate_minimum <> 0 and
               cppgeneral:specific_minimum[2] = 1 then
                {
                cppgeneral:specific_rate_minimum/column=72
                "M.F."
                }
            }
        ""/newline
        }

--    if cppgeneral:coinsurance_factor[1] <> 1.00 then
--        {                                                       
        "Coinsurance Factor:"/column=1
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:coinsurance_factor[1]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:coinsurance_factor_b[1]/column=63
            }
        ""/newline
--        }

    if cppgeneral:public_institutional = 1 then
        {                              
        "Public & Institutional:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:public_institute_factor[1]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:public_institute_factor[1]/column=63
            }                                   
        ""/newline
        }

    if cppgeneral:fire_resistive_rate[1] <> 1.00 then
        {               
        "Fire Resistive:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:fire_resistive_rate[1]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:fire_resistive_rate[4]/column=63
            }                                
        ""/newline
        }                                    

    if cppgeneral:security_factor[1] <> 1.00 then
        {               
        "Security Protection:"/column=1
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:security_factor[1]/column=34
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:security_factor[1]/column=64
            }                                
        ""/newline
        }                                    

    if cppgeneral:burglary_factor[1] <> 1.00 then
        {               
        "Burglar Alarm:"/column=1
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:burglary_factor[1]/column=34
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:burglary_factor[1]/column=64
            }                                
        ""/newline
        }                                    

    if cppgeneral:sprinklered = 1 then
        {                                                  
        "Sprinklered:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:sprinklered_rate[1]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:sprinklered_rate[2]/column=63
            }
        ""/newline
        }

    if cppgeneral:agreed_value = 1 then
        {                                    
        "Agreed Value:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:agreed_value_factor[1]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:agreed_value_factor[1]/column=63 
            }                                
        ""/newline
        }

    if cppgeneral:inflation_factor[1] <> 1.00 then
        {                   
        "Inflation Factor:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:inflation_factor[1]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:inflation_factor[1]/column=63
            }                              
        ""/newline
        }

    if cppgeneral:vacancy_factor[1] <> 1.00 then
        {                                   
        "Vacancy Factor:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:vacancy_factor[1]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:vacancy_factor[1]/column=63
            }                            
        ""/newline
        }

/*    if cppgeneral:contents_deduct_factor[1] <> 1.00 or
       cppgeneral:deductible_factor[1] <> 1.00 then
        {                                                */
        "Deductible Factor:"/column=1 
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:deductible_factor[1]/column=33
            } 
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:contents_deduct_factor[1]/column=63 
            }                                    
        ""/newline
--        }                                              

/*    if cppgeneral:wind_deductible_factor[1] <> 1.00 then
        {                                                */
        "Wind Deductible:" /column=1
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:wind_deductible_factor[1]/column=33
            } 
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:wind_deductible_factor[2]/column=63 
            }                                    
        ""/newline
--        }                                            

    if cppgeneral:state = 19 and
       sfpname:company_id = "FARMERS" then 
        {                                                
        "Territory Factor:"/column=1
        if cppgeneral:limit[1] <> 0 then      
            {
            cppgeneral:territory_factor_2[1]/column=33/mask="ZZZ.ZZZ"
            }
        if cppgeneral:limit[2] <> 0 then      
            {
            cppgeneral:territory_factor_2[1]/column=63/mask="ZZZ.ZZZ"
            }                                           
        ""/newline
        }

--    if cppgeneral:company_deviation[1] <> 1.00 then
--        {                                                    
        "Co Deviation:"
        if cppgeneral:limit[1] <> 0 then
            {             
            if cppgeneral:company_deviation[1] <> 1 and
               cpsdefault:deviation_number_not_factor = 1 then
                {
                (1 + (cppgeneral:company_deviation[1] * 0.01))/column=29
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
                (1 + (cppgeneral:company_deviation[1] * 0.01))/column=59
                }
            else  
                {
                cppgeneral:company_deviation[1]/column=62
                }
            }                               
        ""/newline
--        }         

    "Per 100:"
    if cppgeneral:limit[1] <> 0 then
        {
        l_limit_1/column=26/mask="ZZ,ZZZ,ZZZ.999"
        }      

    if cppgeneral:limit[2] <> 0 then
        {
        l_limit_2/column=56/mask="ZZ,ZZZ,ZZZ.999"
        }                                        
    ""/newline

    if sfscompany:boiler_rating = 2 then 
        {                                                
        "Rating Territory Factor:"/column=1
        if cppgeneral:limit[1] <> 0 then      
            {
            cppgeneral:rating_territory_factor/column=33
            }
        if cppgeneral:limit[2] <> 0 then      
            {
            cppgeneral:rating_territory_factor/column=63
            }                                           
        ""/newline
        }

--    if cppgeneral:package_mod[1] <> 1.00 then
--        {                                                   
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
        ""/newline
--        }
                                             
    ""/newline
    "Total Fire:"
    if cppgeneral:limit[1] <> 0 then
        {                                 
        cppgeneral:premium[1]/column=27
        }
    if cppgeneral:limit[2] <> 0 then
        {
        cppgeneral:premium[7]/column=57
        }
    ""/newline=2
    }
                             

sorted by cppgeneral:prem_no
          cppgeneral:build_no
