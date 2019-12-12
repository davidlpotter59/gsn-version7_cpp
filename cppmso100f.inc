/* cppmso100f.inc
  
   scips.com

   April 20, 2007

   inland marine worksheet
*/

writefile(l_dec,"%s",l_arial)

if cppinland:policy_no    = sfpprint8:policy_no and
   cppinland:pol_year     = sfpprint8:pol_year and
   cppinland:end_sequence = sfpprint8:end_sequence then
    begin
    writefile(l_dec,"%s","<033>$a2000h+0V")
    writefile(l_dec,"%s","INLAND MARINE")
    writefile(l_dec,"%s","<NL>")
    writefile(l_dec,"%s","<NL>")
    end

l_prem_no  = 0
l_build_no = 0
while cppinland:policy_no    = sfpprint8:policy_no and
      cppinland:pol_year     = sfpprint8:pol_year and
      cppinland:end_sequence = sfpprint8:end_sequence 
        begin
        access cppendorse, set cppendorse:policy_no    = cppinland:policy_no,
                               cppendorse:pol_year     = cppinland:pol_year,
                               cppendorse:end_sequence = cppinland:end_sequence,
                               cppendorse:prem_no      = cppinland:prem_no,
                               cppendorse:build_no     = cppinland:build_no, generic

        access sfplocation, set sfplocation:policy_no    = cppinland:policy_no,
                                sfplocation:pol_year     = cppinland:pol_year,
                                sfplocation:end_sequence = cppinland:end_sequence, 
                                sfplocation:prem_no      = cppinland:prem_no,
                                sfplocation:build_no     = cppinland:build_no, generic

        l_state  = cppinland:state
        l_county = cppinland:county
        l_lob    = cppinland:rating_line_of_business
        access sfsstate, set sfsstate:company_id = sfpname:company_id,
                             sfsstate:state      = l_state,
                             sfsstate:county     = "00", generic

        access sfsstate_alias, set sfsstate_alias:company_id = sfpname:company_id,
                                   sfsstate_alias:state      = l_state,
                                   sfsstate_alias:county     = l_county, generic

        if cppinland:prem_no  <> l_prem_no or
           cppinland:build_no <> l_build_no then
            begin
            if l_first = "N" then
                writefile(l_dec,"%s","<FF>")
            if l_first = "Y" then
                l_first = "N" 
            l_prem_no  = cppinland:prem_no
            l_build_no = cppinland:build_no
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s",l_arial)
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s%s","Location:  ",str(cppinland:prem_no,"ZZZZ"))
            writefile(l_dec,"%s","<033>&a1000h+0V")
            writefile(l_dec,"%s%s","Building:  ",str(cppinland:build_no,"ZZZZ"))
            writefile(l_dec,"%s","<033>&a2300h+0V")
            writefile(l_dec,"%s",trun(sfplocation:address))
            writefile(l_dec,"%s","<NL>")
            if sfplocation:address1[1] <> "" then
                begin
                writefile(l_dec,"%s","<033>&a2300h+0V")
                writefile(l_dec,"%s",trun(sfplocation:address1[1]))
                writefile(l_dec,"%s","<NL>")
                end
            if sfplocation:address1[2] <> "" then
                begin
                writefile(l_dec,"%s","<033>&a2300h+0V")
                writefile(l_dec,"%s",trun(sfplocation:address1[2]))
                writefile(l_dec,"%s","<NL>")
                end
            if sfplocation:address1[3] <> "" then
                begin
                writefile(l_dec,"%s","<033>&a2300h+0V")
                writefile(l_dec,"%s",trun(sfplocation:address1[3]))
                writefile(l_dec,"%s","<NL>")
                end
            writefile(l_dec,"%s","<033>&a2300h+0V")
            writefile(l_dec,"%s%s%s%s%s",trun(sfplocation:city),
                                         ", ",
                                         sfplocation:str_state,
                                         " ",
                                         str(sfplocation:zipcode,"99999-9999"))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<NL>")

            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s%s%s%s","Business Desc:  ",
                                       trun(cppinland:business_description[1]),
                                       " ",
                                       trun(cppinland:business_description[2]))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<NL>")

            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s%s%s%s","State:  ",str(cppinland:state)," ",trun(sfsstate:description))
            writefile(l_dec,"%s","<033>&a2300h+0V")
            writefile(l_dec,"%s%s%s%s","County:  ",str(cppinland:county)," ",trun(sfsstate_alias:description))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<NL>")
            end
        else
            begin
            writefile(l_dec,"%s","<NL>")
            end

        writefile(l_dec,"%s","<033>&a300h+0V")
        writefile(l_dec,"%s",cppinland:form_edition)
        writefile(l_dec,"%s","<033>&a1300h+0V")
        writefile(l_dec,"%s",cppinland:description)
        writefile(l_dec,"%s","<NL>")
        if cppinland:premium <> 0 then
            begin
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Deductible")
            writefile(l_dec,"%s","<033>&a1525h+0V")
            writefile(l_dec,"%s",str(cppendorse:deductible[1],"ZZZZZ"))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Rate")
            writefile(l_dec,"%s","<033>&a1450h+0V")
            writefile(l_dec,"%s",str(cppendorse:rate[1],"ZZZ.ZZZ"))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Limit")
            writefile(l_dec,"%s","<033>&a1300h+0V")
            writefile(l_dec,"%s",str(cppendorse:limit[1],"ZZZ,ZZZ,ZZZ"))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Premium")
            writefile(l_dec,"%s","<033>&a1300h+0V")
            writefile(l_dec,"%s",str(cppinland:total_premium,"$$$,$$$.99"))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Company Deviation")
            writefile(l_dec,"%s","<033>&a1500h+0V")
            writefile(l_dec,"%s",str(cppinland:company_deviation,"ZZ.ZZ"))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","PMA Factor")
            writefile(l_dec,"%s","<033>&a1500h+0V")
            writefile(l_dec,"%s",str(cppinland:package_mod,"ZZ.ZZ"))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<033>&a300h+0V")
            writefile(l_dec,"%s","Total Premium")
            writefile(l_dec,"%s","<033>&a1300h+0V")
            writefile(l_dec,"%s",str(cppinland:premium,"$$$,$$$.99"))
            writefile(l_dec,"%s","<NL>")
            writefile(l_dec,"%s","<NL>")
            end

        next cppinland
        end
