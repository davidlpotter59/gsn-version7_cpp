/* cpqmso100g.inc  
   scips.com
   July 31, 2007
   Farmowners worksheet
*/

unsigned ascii number l_line_counter=1 ;
unsigned ascii number l_max_lines=40 ;

writefile(l_dec,"%s",l_arial)
access cpqfarmlimits,
   set cpqfarmlimits:quote_no = cpqfarm:quote_no, generic

access cpqfarmliab,
   set cpqfarmliab:quote_no = cpqfarm:quote_no, generic

access cpqfarmcovb,
   set cpqfarmcovb:quote_no = cpqfarm:quote_no,
       cpqfarmcovb:prem_no  = cpqfarm:prem_no,
       cpqfarmcovb:build_no = cpqfarm:build_no, generic

access cpqfarmcovc,
   set cpqfarmcovc:quote_no = cpqfarm:quote_no,
       cpqfarmcovc:prem_no  = cpqfarm:prem_no,
       cpqfarmcovc:build_no = cpqfarm:build_no, generic

access cpqfarmcovd,
   set cpqfarmcovd:quote_no = cpqfarm:quote_no,
       cpqfarmcovd:prem_no  = cpqfarm:prem_no,
       cpqfarmcovd:build_no = cpqfarm:build_no, generic

access cpqfarmcove,
   set cpqfarmcove:quote_no = cpqfarm:quote_no,
       cpqfarmcove:prem_no  = cpqfarm:prem_no,
       cpqfarmcove:build_no = cpqfarm:build_no, generic

access cpqfarmmisc,
   set cpqfarmmisc:quote_no = cpqfarm:quote_no,
       cpqfarmmisc:prem_no  = cpqfarm:prem_no,
       cpqfarmmisc:build_no = cpqfarm:build_no, generic

Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s%s","Location: ",str(cpqfarm:prem_no))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1.25

Writefile(l_dec,"%s","<033>&a1500h+0V")
writefile(l_dec,"%s%s","Building: ",str(cpqfarm:build_no))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+30V")
writefile(l_dec,"%s%s","Location: ",trun(sfqname:address[1]))
Writefile(l_dec,"%s"," ")
Writefile(l_dec,"%s",trun(sfqname:city))
Writefile(l_dec,"%s",", ")
Writefile(l_dec,"%s",sfqname:str_state)
Writefile(l_dec,"%s"," ")
Writefile(l_dec,"%s",sfqname:str_zipcode)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1.25

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","State: ",cpqfarm:state)
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","County: ",cpqfarm:county)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+120V")
writefile(l_dec,"%s%n","Form:  ",cpqfarmlimits:form)
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Occurrence:  ",str(cpqfarmlimits:occurrence,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 2

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","General Aggregate:  ",str(cpqfarmlimits:general_aggregate,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Products Aggregate:  ",str(cpqfarmlimits:products,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Medical Payments:  ",str(cpqfarmlimits:medical_payments,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Fire Legal:  ",str(cpqfarmlimits:fire_legal,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Advertising Personal Injury:  ",str(cpqfarmlimits:advertising_personal_injury,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Deductible:  ",str(cpqfarm:deductible,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","IRPM:  ",str(cpqfarm:deductible,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","Wind Deductible: ",cpqfarm:wind_deductible)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Coinsurance: ",CPQFARM:coinsurance)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+120V")
writefile(l_dec,"%s%n","Group No: ",cpqfarmliab:group_no)
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","Class Code: ",cpqfarmliab:class_code)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 2

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Prem/Ops Exposure: ",cpqfarmliab:exposure[1])
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Exposure Base: ",cpqfarmliab:exposure_base[1])
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Per: ",cpqfarmliab:rates_per[1])
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","Rate: ",cpqfarmliab:base_rate[1])
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Products Exposure: ",cpqfarmliab:exposure[2])
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Exposure Base: ",cpqfarmliab:exposure_base[2])
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Per: ",cpqfarmliab:rates_per[2])
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","Rate: ",cpqfarmliab:base_rate[2])
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Limits Table: ",cpqfarmliab:limits_table)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cpqfarmcova,
   set cpqfarmcova:quote_no = cpqfarm:quote_no,
       cpqfarmcova:prem_no  = cpqfarm:prem_no,
       cpqfarmcova:build_no = cpqfarm:build_no, generic

while cpqfarmcova:quote_no = cpqfarm:quote_no and
      cpqfarmcova:prem_no  = cpqfarm:prem_no and
      cpqfarmcova:build_no = cpqfarm:build_no
{
Writefile(l_dec,"%s","<033>&a1500h+120V")
writefile(l_dec,"%s","Coverage A: ")
l_line_counter = l_line_counter + 1
  If cpqfarmcova:protection = 0 and cpqfarmcova:construction = 0 and
     cpqfarmcova:owner_occupied = 0 and cpqfarmcova:theft_exclusion = 0 and
     cpqfarmcova:vandalism_exclusion = 0 and cpqfarmcova:wind_exclusion = 0 and
     cpqfarmcova:limit = 0 and cpqfarmcova:rate = 0 and cpqfarmcova:premium = 0 then
    {
      writefile(l_dec,"%S","N/A ")
    }

  If cpqfarmcova:protection <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%S%n","Protection: ",cpqfarmcova:Protection)
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcova:construction <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Construction: ",cpqfarmcova:construction)
    }

  If cpqfarmcova:owner_occupied <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%n","Owner Occupied: ",cpqfarmcova:owner_occupied)
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcova:theft_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Theft Excluded: ",cpqfarmcova:theft_exclusion)
    }

  If cpqfarmcova:vandalism_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%n","Vandalism Excluded: ",cpqfarmcova:vandalism_exclusion)
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcova:wind_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Wind Excluded: ",cpqfarmcova:wind_exclusion)
    }

  If cpqfarmcova:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cpqfarmcova:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcova:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cpqfarmcova:Rate)
    }

  If cpqfarmcova:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cpqfarmcova:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }


  next cpqfarmcova
}
  Writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cpqfarmcovb,
   set cpqfarmcovb:quote_no = cpqfarm:quote_no,
       cpqfarmcovb:prem_no  = cpqfarm:prem_no,
       cpqfarmcovb:build_no = cpqfarm:build_no, generic

while cpqfarmcovb:quote_no = cpqfarm:quote_no and
      cpqfarmcovb:prem_no  = cpqfarm:prem_no and
      cpqfarmcovb:build_no = cpqfarm:build_no
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Coverage B: ")
l_line_counter = l_line_counter + 0.25

  If cpqfarmcovb:protection = 0 and cpqfarmcovb:theft_exclusion = 0 and
     cpqfarmcovb:vandalism_exclusion = 0 and cpqfarmcovb:wind_exclusion = 0 and
     cpqfarmcovb:limit = 0 and cpqfarmcovb:rate = 0 and cpqfarmcovb:premium = 0 then
    {
      writefile(l_dec,"%S","N/A ")
    }

  If cpqfarmcovb:protection <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%S%n","Protection: ",cpqfarmcovb:Protection)
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcovb:theft_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Theft Excluded: ",cpqfarmcovb:theft_exclusion)
    }

  If cpqfarmcovb:vandalism_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%n","Vandalism Excluded: ",cpqfarmcovb:vandalism_exclusion)
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcovb:wind_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Wind Excluded: ",cpqfarmcovb:wind_exclusion)
    }

  If cpqfarmcovb:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cpqfarmcovb:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcovb:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cpqfarmcovb:Rate)
    }

  If cpqfarmcovb:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cpqfarmcovb:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  next cpqfarmcovb
}
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cpqfarmcovc,
   set cpqfarmcovc:quote_no = cpqfarm:quote_no,
       cpqfarmcovc:prem_no  = cpqfarm:prem_no,
       cpqfarmcovc:build_no = cpqfarm:build_no, generic

while cpqfarmcovc:quote_no = cpqfarm:quote_no and
      cpqfarmcovc:prem_no  = cpqfarm:prem_no and
      cpqfarmcovc:build_no = cpqfarm:build_no
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Coverage C: ")
l_line_counter = l_line_counter + 0.25

  If cpqfarmcovc:protection = 0 and cpqfarmcovc:theft_exclusion = 0 and
     cpqfarmcovc:vandalism_exclusion = 0 and cpqfarmcovc:wind_exclusion = 0 and
     cpqfarmcovc:limit = 0 and cpqfarmcovc:rate = 0 and cpqfarmcovc:premium = 0 then
    {
      writefile(l_dec,"%S","N/A ")
    }

  If cpqfarmcovc:protection <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%S%n","Protection: ",cpqfarmcovc:Protection)
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcovc:theft_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Theft Excluded: ",cpqfarmcovc:theft_exclusion)
    }

  If cpqfarmcovc:vandalism_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%n","Vandalism Excluded: ",cpqfarmcovc:vandalism_exclusion)
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcovc:wind_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Wind Excluded: ",cpqfarmcovc:wind_exclusion)
    }

  If cpqfarmcovc:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cpqfarmcovc:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  If cpqfarmcovc:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cpqfarmcovc:Rate)
    }

  If cpqfarmcovc:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cpqfarmcovc:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }
  next cpqfarmcovc
}
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cpqfarmcovd,
   set cpqfarmcovd:quote_no = cpqfarm:quote_no,
       cpqfarmcovd:prem_no  = cpqfarm:prem_no,
       cpqfarmcovd:build_no = cpqfarm:build_no, generic

while cpqfarmcovd:quote_no = cpqfarm:quote_no and
      cpqfarmcovd:prem_no  = cpqfarm:prem_no and
      cpqfarmcovd:build_no = cpqfarm:build_no
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Coverage D: ")
l_line_counter = l_line_counter + 0.25

  If cpqfarmcovd:protection = 0 and cpqfarmcovd:theft_exclusion = 0 and
     cpqfarmcovd:vandalism_exclusion = 0 and cpqfarmcovd:wind_exclusion = 0 and
     cpqfarmcovd:limit = 0 and cpqfarmcovd:rate = 0 and cpqfarmcovd:premium = 0 then
    {
      writefile(l_dec,"%S","N/A ")
    }

  if cpqfarmcovd:protection <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%S%n","Protection: ",cpqfarmcovd:Protection)
l_line_counter = l_line_counter + 1
    }

  if cpqfarmcovd:theft_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Theft Excluded: ",cpqfarmcovd:theft_exclusion)
    }

  if cpqfarmcovd:vandalism_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%n","Vandalism Excluded: ",cpqfarmcovd:vandalism_exclusion)
l_line_counter = l_line_counter + 1
    }

  if cpqfarmcovd:wind_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Wind Excluded: ",cpqfarmcovd:wind_exclusion)
    }

  if cpqfarmcovd:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cpqfarmcovd:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  if cpqfarmcovd:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cpqfarmcovd:Rate)
    }

  if cpqfarmcovd:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cpqfarmcovd:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  next cpqfarmcovd
}
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cpqfarmcove,
   set cpqfarmcove:quote_no = cpqfarm:quote_no,
       cpqfarmcove:prem_no  = cpqfarm:prem_no,
       cpqfarmcove:build_no = cpqfarm:build_no, generic

while cpqfarmcove:quote_no = cpqfarm:quote_no and
      cpqfarmcove:prem_no  = cpqfarm:prem_no and
      cpqfarmcove:build_no = cpqfarm:build_no
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Coverage E: ")
l_line_counter = l_line_counter + 0.25

  If cpqfarmcove:protection = 0 and cpqfarmcove:theft_exclusion = 0 and
     cpqfarmcove:vandalism_exclusion = 0 and cpqfarmcove:wind_exclusion = 0 and
     cpqfarmcove:limit = 0 and cpqfarmcove:rate = 0 and cpqfarmcove:premium = 0 then
    {
      writefile(l_dec,"%S","N/A ")
    }

  if cpqfarmcove:protection <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%S%n","Protection: ",cpqfarmcove:Protection)
l_line_counter = l_line_counter + 1
    }

  if cpqfarmcove:theft_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Theft Excluded: ",cpqfarmcove:theft_exclusion)
    }

  if cpqfarmcove:vandalism_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%n","Vandalism Excluded: ",cpqfarmcove:vandalism_exclusion)
l_line_counter = l_line_counter + 1
    }

  if cpqfarmcove:wind_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Wind Excluded: ",cpqfarmcove:wind_exclusion)
    }

  if cpqfarmcove:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cpqfarmcove:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  if cpqfarmcove:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cpqfarmcove:Rate)
    }

  if cpqfarmcove:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cpqfarmcove:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }
  next cpqfarmcove
}

writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

if l_line_counter >= l_max_lines-5 then
  {
    Writefile(l_dec,"%s","<FF>")
  }

access cpqfarmmisc,
   set cpqfarmmisc:quote_no = cpqfarm:quote_no,
       cpqfarmmisc:prem_no  = cpqfarm:prem_no,
       cpqfarmmisc:build_no = cpqfarm:build_no, generic

while cpqfarmmisc:quote_no = cpqfarm:quote_no and
      cpqfarmmisc:prem_no  = cpqfarm:prem_no and
      cpqfarmmisc:build_no = cpqfarm:build_no
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Miscellaneous: ")
l_line_counter = l_line_counter + 0.25

  If cpqfarmmisc:protection = 0 and cpqfarmmisc:theft_exclusion = 0 and
     cpqfarmmisc:vandalism_exclusion = 0 and cpqfarmmisc:wind_exclusion = 0 and
     cpqfarmmisc:limit = 0 and cpqfarmmisc:rate = 0 and cpqfarmmisc:premium = 0 then
    {
      writefile(l_dec,"%S","N/A ")
    }

  if cpqfarmmisc:protection <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%S%n","Protection: ",cpqfarmmisc:Protection)
l_line_counter = l_line_counter + 1
    }

  if cpqfarmmisc:theft_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Theft Excluded: ",cpqfarmmisc:theft_exclusion)
    }

  if cpqfarmmisc:vandalism_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%n","Vandalism Excluded: ",cpqfarmmisc:vandalism_exclusion)
l_line_counter = l_line_counter + 1
    }

  if cpqfarmmisc:wind_exclusion <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Wind Excluded: ",cpqfarmmisc:wind_exclusion)
    }

  if cpqfarmmisc:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cpqfarmmisc:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  if cpqfarmmisc:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cpqfarmmisc:Rate)
    }

  if cpqfarmmisc:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cpqfarmmisc:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }
  next cpqfarmmisc
}
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1
