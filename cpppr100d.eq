/* cpppr100d.eq
  
   scips.com

   March 28, 2003

   property worksheet - VMM
*/

define unsigned ascii number l_limit_1 = cppgeneral:limit[1] divide 100
                             l_limit_2 = cppgeneral:limit[2] divide 100

where cppgeneral:policy_no = sfpprint5:policy_no and
      cppgeneral:pol_Year = sfpprint5:pol_year and
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
if cppgeneral:form >= 2 then
    {
    "VMM:"       
    if cppgeneral:limit[1] <> 0 then
        {
        cppgeneral:base_rate[3]/column=33
        if cppgeneral:new_rate[3] <> 0 then
            cppgeneral:new_rate[3]
        }
    if cppgeneral:limit[2] <> 0 then
        {
        cppgeneral:base_rate[9]/column=63
        if cppgeneral:new_rate[9] <> 0 then
            cppgeneral:new_rate[9]
        }    

--    if cppgeneral:coinsurance_factor[3] <> 1.00 then
--        {                                   
        ""/newline                    
        "Coinsurance Factor:"/column=1
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:coinsurance_factor[3]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:coinsurance_factor_b[3]/column=63
            }
--        }

    if cppgeneral:public_institutional = 1 then
        {                                    
        ""/newline
        "Public & Institutional:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:public_institute_factor[3]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:public_institute_factor[3]/column=63
            }
        }

    if cppgeneral:fire_resistive_rate[3] <> 1.00 then
        {                                            
        ""/newline
        "Fire Resistive:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:fire_resistive_rate[3]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:fire_resistive_rate[6]/column=63
            }
        }

    if cppgeneral:security_factor[3] <> 1.00 then
        {                                            
        ""/newline
        "Security Protection:"/column=1
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:security_factor[3]/column=34
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:security_factor[3]/column=64
            }
        }

    if cppgeneral:burglary_factor[3] <> 1.00 then
        {                                            
        ""/newline
        "Burglar Alarm:"/column=1
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:burglary_factor[3]/column=34
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:burglary_factor[3]/column=64
            }
        }

    if cppgeneral:sprinklered = 1 then
        {                                     
        ""/newline             
        "Sprinklered:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:sprinklered_rate[1]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:sprinklered_rate[2]/column=63
            }
        }

    if cppgeneral:agreed_value = 1 then
        {                                  
        ""/newline  
        "Agreed Value:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:agreed_value_factor[3]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:agreed_value_factor[3]/column=63 
            }
        }

    if cppgeneral:inflation_factor[3] <> 1.00 then
        {                   
        ""/newline
        "Inflation Factor:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:inflation_factor[3]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:inflation_factor[3]/column=63
            }
        }

    if cppgeneral:vacancy_factor[3] <> 1.00 then
        {                                  
        ""/newline 
        "Vacancy Factor:"
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:vacancy_factor[3]/column=33
            }
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:vacancy_factor[3]/column=63
            }
        }

/*    if cppgeneral:contents_deduct_factor[3] <> 1.00 or
       cppgeneral:deductible_factor[3] <> 1.00 then
        {                                                */
        ""/newline
        "Deductible Factor:"/column=1 
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:deductible_factor[3]/column=33
            } 
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:contents_deduct_factor[3]/column=63 
            }
--        }                                              

--    if cppgeneral:wind_deductible_factor[3] <> 1.00 then
--        {                                                
        ""/newline
        "Wind Deductible:" /column=1
        if cppgeneral:limit[1] <> 0 then
            {
            cppgeneral:wind_deductible_factor[3]/column=33
            } 
        if cppgeneral:limit[2] <> 0 then
            {
            cppgeneral:wind_deductible_factor[3]/column=63 
            }
--        }                                              

    if cppgeneral:state = 19 and
       sfpname:company_id = "FARMERS" then 
        {                                                
        ""/newline
        "Territory Factor:"/column=1
        if cppgeneral:limit[1] <> 0 then      
            {
            cppgeneral:territory_factor_2[3]/column=33/mask="ZZZ.ZZZ"
            }
        if cppgeneral:limit[2] <> 0 then      
            {
            cppgeneral:territory_factor_2[3]/column=63/mask="ZZZ.ZZZ"
            }                                           
        ""/newline
        }
--    if cppgeneral:company_deviation[3] <> 1.00 then
--        {                                                    
        "Co Deviation:"/column=1
        if cppgeneral:limit[1] <> 0 then
            {               
            if cppgeneral:company_deviation[3] <> 1 and
               cpsdefault:deviation_number_not_factor = 1 then
                {
                (1 + (cppgeneral:company_deviation[3] * 0.01))/column=29
                }
            else 
                {
                cppgeneral:company_deviation[3]/column=32
                }
            }                              
        if cppgeneral:limit[2] <> 0 then
            {
            if cppgeneral:company_deviation[3] <> 1 and
               cpsdefault:deviation_number_not_factor = 1 then
                {
                (1 + (cppgeneral:company_deviation[3] * 0.01))/column=59
                }
            else 
                {
                cppgeneral:company_deviation[3]/column=62
                }
            }
--        }         
                                            
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

--    if cppgeneral:package_mod[3] <> 1.00 then
--        {                                                   
        ""/newline
        "PMA Factor:"
        if cppgeneral:limit[1] <> 0 then
            {
            if cppgeneral:package_mod[3] <> 1 and
               cpsdefault:deviation_number_not_factor = 1 then
                {
                (1 + (cppgeneral:package_mod[3] * 0.01))/column=29
                }
            else 
                {
                cppgeneral:package_mod[3]/column=32
                }
            }
        if cppgeneral:limit[2] <> 0 then
            {
            if cppgeneral:package_mod[3] <> 1 and
               cpsdefault:deviation_number_not_factor = 1 then
                {
                (1 + (cppgeneral:package_mod[3] * 0.01))/column=59
                } 
            else 
                {
                cppgeneral:package_mod[3]/column=62
                }
            }
--        }
                                             
    ""/newline=2
    "Total VMM:"
    if cppgeneral:limit[1] <> 0 then
        {                                 
        cppgeneral:premium[3]/column=27
        }
    if cppgeneral:limit[2] <> 0 then
        {
        cppgeneral:premium[9]/column=57
        }                     
    ""/newline=2
    }

sorted by cppgeneral:prem_no
          cppgeneral:build_no
