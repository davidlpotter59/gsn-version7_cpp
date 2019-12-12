/* cppmso100g.inc  
   scips.com
   July 31, 2007
   Farmowners worksheet
*/

unsigned ascii number l_line_counter=1;
unsigned ascii number l_max_lines=40 ;

writefile(l_dec,"%s",l_arial)
access cppfarmlimits,
   set cppfarmlimits:policy_no = cppfarm:policy_no, generic

access cppfarmcovb,
   set cppfarmcovb:policy_no = cppfarm:policy_no,
       cppfarmcovb:pol_year  = cppfarm:pol_year,
       cppfarmcovb:end_sequence = cppfarm:end_sequence, generic

access cppfarmcovc,
   set cppfarmcovc:policy_no = cppfarm:policy_no,
       cppfarmcovc:pol_year  = cppfarm:pol_year,
       cppfarmcovc:end_sequence = cppfarm:end_sequence, generic

access cppfarmcovd,
   set cppfarmcovd:policy_no = cppfarm:policy_no,
       cppfarmcovd:pol_year  = cppfarm:pol_year,
       cppfarmcovd:end_sequence = cppfarm:end_sequence, generic

access cppfarmcove,
   set cppfarmcove:policy_no = cppfarm:policy_no,
       cppfarmcove:pol_year  = cppfarm:pol_year,
       cppfarmcove:end_sequence = cppfarm:end_sequence, generic

access cppfarmmisc,
   set cppfarmmisc:policy_no = cppfarm:policy_no,
       cppfarmmisc:pol_year  = cppfarm:pol_year,
       cppfarmmisc:end_sequence = cppfarm:end_sequence, generic

Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s%s","Location: ",str(cppfarm:prem_no))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1.25

Writefile(l_dec,"%s","<033>&a1500h+0V")
writefile(l_dec,"%s%s","Building: ",str(cppfarm:build_no))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+30V")
writefile(l_dec,"%s%s","Location: ",trun(sfpname:address[1]))
Writefile(l_dec,"%s"," ")
Writefile(l_dec,"%s",trun(sfpname:city))
Writefile(l_dec,"%s",", ")
Writefile(l_dec,"%s",sfpname:str_state)
Writefile(l_dec,"%s"," ")
Writefile(l_dec,"%s",sfpname:str_zipcode)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1.25

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","State: ",cppfarm:state)
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","County: ",cppfarm:county)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+120V")
writefile(l_dec,"%s%n","Form:  ",cppfarmlimits:form)
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Occurrence:  ",str(cppfarmlimits:occurrence,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 2

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","General Aggregate:  ",str(cppfarmlimits:general_aggregate,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Products Aggregate:  ",str(cppfarmlimits:products,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Medical Payments:  ",str(cppfarmlimits:medical_payments,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Fire Legal:  ",str(cppfarmlimits:fire_legal,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Advertising Personal Injury:  ",str(cppfarmlimits:advertising_personal_injury,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Deductible:  ",str(cppfarm:deductible,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","IRPM:  ",str(cppfarm:deductible,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","Wind Deductible: ",cppfarm:wind_deductible)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Coinsurance: ",cppFARM:coinsurance)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cppfarmcova,
   set cppfarmcova:policy_no = cppfarm:policy_no,
       cppfarmcova:pol_year  = cppfarm:pol_year,
       cppfarmcova:end_sequence = cppfarm:end_sequence, generic

while cppfarmcova:policy_no = cppfarm:policy_no and
      cppfarmcova:pol_year  = cppfarm:pol_year and
      cppfarmcova:end_sequence = cppfarm:end_sequence
{
  Writefile(l_dec,"%s","<033>&a1500h+120V")
  writefile(l_dec,"%s","Coverage A: ")
  l_line_counter = l_line_counter + 1

  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%S","Protection:  ")
      l_line_counter = l_line_counter + 1

  If cppfarmcova:protection = 1 then
    {
      writefile(l_dec,"%S","Protected")
    }

  If cppfarmcova:protection = 2 then
    {
      writefile(l_dec,"%S","Semi-protected")
    }

  If cppfarmcova:protection = 3 then
    {
      writefile(l_dec,"%S","Unprotected")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Construction: ")

  If cppfarmcova:construction = 1 then
    {
      writefile(l_dec,"%s","Combustible")
    }

  If cppfarmcova:construction = 2 then
    {
      writefile(l_dec,"%s","Joisted Masonry")
    }

  If cppfarmcova:construction = 3 then
    {
      writefile(l_dec,"%s","Non-Combustible")
    }

  If cppfarmcova:construction = 4 then
    {
      writefile(l_dec,"%s","Masonry Non-Combustible")
    }

  If cppfarmcova:construction = 5 then
    {
      writefile(l_dec,"%s","Modified Fire Resistive")
    }

  If cppfarmcova:construction = 6 then
    {
      writefile(l_dec,"%s","Fire Resistive")
    }

  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%s","Owner Occupied: ")
  l_line_counter = l_line_counter + 1

  If cppfarmcova:owner_occupied > 0 then
    {
      writefile(l_dec,"%s","Y")
    }
  else
    {
      writefile(l_dec,"%s","N")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Theft Excluded: ")

  If cppfarmcova:theft_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }


  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%s","Vandalism Excluded: ")
  l_line_counter = l_line_counter + 1

  If cppfarmcova:vandalism_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Wind Excluded: ")

  If cppfarmcova:wind_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  If cppfarmcova:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cppfarmcova:Limit,"ZZ,ZZZ,ZZZ.99"))
      l_line_counter = l_line_counter + 1
    }

  If cppfarmcova:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cppfarmcova:Rate)
    }

  If cppfarmcova:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cppfarmcova:premium,"Z,ZZZ.99"))
      l_line_counter = l_line_counter + 1
    }

  next cppfarmcova
}
  Writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cppfarmcovb,
   set cppfarmcovb:policy_no = cppfarm:policy_no,
       cppfarmcovb:pol_year  = cppfarm:pol_year,
       cppfarmcovb:end_sequence = cppfarm:end_sequence, generic

while cppfarmcovb:policy_no = cppfarm:policy_no and
      cppfarmcovb:pol_year  = cppfarm:pol_year and
      cppfarmcovb:end_sequence = cppfarm:end_sequence
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Coverage B: ")
l_line_counter = l_line_counter + 0.25

  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%S","Protection:  ")
      l_line_counter = l_line_counter + 1

  If cppfarmcovb:protection = 1 then
    {
      writefile(l_dec,"%S","Protected")
    }

  If cppfarmcovb:protection = 2 then
    {
      writefile(l_dec,"%S","Semi-protected")
    }

  If cppfarmcovb:protection = 3 then
    {
      writefile(l_dec,"%S","Unprotected")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Theft Excluded: ")

  If cppfarmcovb:theft_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }


  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%s","Vandalism Excluded: ")
  l_line_counter = l_line_counter + 1

  If cppfarmcovb:vandalism_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Wind Excluded: ")

  If cppfarmcovb:wind_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  If cppfarmcovb:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cppfarmcovb:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  If cppfarmcovb:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cppfarmcovb:Rate)
    }

  If cppfarmcovb:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cppfarmcovb:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  next cppfarmcovb
}
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cppfarmcovc,
   set cppfarmcovc:policy_no = cppfarm:policy_no,
       cppfarmcovc:pol_year  = cppfarm:pol_year,
       cppfarmcovc:end_sequence = cppfarm:end_sequence, generic

while cppfarmcovc:policy_no = cppfarm:policy_no and
      cppfarmcovc:pol_year  = cppfarm:pol_year and
      cppfarmcovc:end_sequence = cppfarm:end_sequence
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Coverage C: ")
l_line_counter = l_line_counter + 0.25

  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%S","Protection:  ")
      l_line_counter = l_line_counter + 1

  If cppfarmcovc:protection = 1 then
    {
      writefile(l_dec,"%S","Protected")
    }

  If cppfarmcovc:protection = 2 then
    {
      writefile(l_dec,"%S","Semi-protected")
    }

  If cppfarmcovc:protection = 3 then
    {
      writefile(l_dec,"%S","Unprotected")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Theft Excluded: ")

  If cppfarmcovc:theft_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }


  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%s","Vandalism Excluded: ")
  l_line_counter = l_line_counter + 1

  If cppfarmcovc:vandalism_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Wind Excluded: ")

  If cppfarmcovc:wind_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  If cppfarmcovc:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cppfarmcovc:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  If cppfarmcovc:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cppfarmcovc:Rate)
    }

  If cppfarmcovc:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cppfarmcovc:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }
  next cppfarmcovc
}
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cppfarmcovd,
   set cppfarmcovd:policy_no = cppfarm:policy_no,
       cppfarmcovd:pol_year  = cppfarm:pol_year,
       cppfarmcovd:end_sequence = cppfarm:end_sequence, generic

while cppfarmcovd:policy_no = cppfarm:policy_no and
      cppfarmcovd:pol_year  = cppfarm:pol_year and
      cppfarmcovd:end_sequence = cppfarm:end_sequence
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Coverage D: ")
l_line_counter = l_line_counter + 0.25

  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%S","Protection:  ")
      l_line_counter = l_line_counter + 1

  If cppfarmcovd:protection = 1 then
    {
      writefile(l_dec,"%S","Protected")
    }

  If cppfarmcovd:protection = 2 then
    {
      writefile(l_dec,"%S","Semi-protected")
    }

  If cppfarmcovd:protection = 3 then
    {
      writefile(l_dec,"%S","Unprotected")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Theft Excluded: ")

  If cppfarmcovd:theft_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }


  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%s","Vandalism Excluded: ")
  l_line_counter = l_line_counter + 1

  If cppfarmcovd:vandalism_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Wind Excluded: ")

  If cppfarmcovd:wind_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  if cppfarmcovd:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cppfarmcovd:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  if cppfarmcovd:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cppfarmcovd:Rate)
    }

  if cppfarmcovd:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cppfarmcovd:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  next cppfarmcovd
}
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

access cppfarmcove,
   set cppfarmcove:policy_no = cppfarm:policy_no,
       cppfarmcove:pol_year  = cppfarm:pol_year,
       cppfarmcove:end_sequence = cppfarm:end_sequence, generic

while cppfarmcove:policy_no = cppfarm:policy_no and
      cppfarmcove:pol_year  = cppfarm:pol_year and
      cppfarmcove:end_sequence = cppfarm:end_sequence
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Coverage E: ")
l_line_counter = l_line_counter + 0.25

  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%S","Protection:  ")
      l_line_counter = l_line_counter + 1

  If cppfarmcove:protection = 1 then
    {
      writefile(l_dec,"%S","Protected")
    }

  If cppfarmcove:protection = 2 then
    {
      writefile(l_dec,"%S","Semi-protected")
    }

  If cppfarmcove:protection = 3 then
    {
      writefile(l_dec,"%S","Unprotected")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Theft Excluded: ")

  If cppfarmcove:theft_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }


  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%s","Vandalism Excluded: ")
  l_line_counter = l_line_counter + 1

  If cppfarmcove:vandalism_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Wind Excluded: ")

  If cppfarmcove:wind_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  if cppfarmcove:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cppfarmcove:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  if cppfarmcove:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cppfarmcove:Rate)
    }

  if cppfarmcove:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cppfarmcove:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }
  next cppfarmcove
}

writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

if l_line_counter >= l_max_lines-5 then
  {
    Writefile(l_dec,"%s","<FF>")
  }

access cppfarmmisc,
   set cppfarmmisc:policy_no = cppfarm:policy_no,
       cppfarmmisc:pol_year  = cppfarm:pol_year,
       cppfarmmisc:end_sequence = cppfarm:end_sequence, generic

while cppfarmmisc:policy_no = cppfarm:policy_no and
      cppfarmmisc:pol_year  = cppfarm:pol_year and
      cppfarmmisc:end_sequence = cppfarm:end_sequence
{
Writefile(l_dec,"%s","<033>&a1500h+30V")
writefile(l_dec,"%s","Miscellaneous: ")
l_line_counter = l_line_counter + 0.25

  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%S","Protection:  ")
      l_line_counter = l_line_counter + 1

  If cppfarmmisc:protection = 1 then
    {
      writefile(l_dec,"%S","Protected")
    }

  If cppfarmmisc:protection = 2 then
    {
      writefile(l_dec,"%S","Semi-protected")
    }

  If cppfarmmisc:protection = 3 then
    {
      writefile(l_dec,"%S","Unprotected")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Theft Excluded: ")

  If cppfarmmisc:theft_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }


  Writefile(l_dec,"%s","<033>&a300h+120V")
  writefile(l_dec,"%s","Vandalism Excluded: ")
  l_line_counter = l_line_counter + 1

  If cppfarmmisc:vandalism_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  Writefile(l_dec,"%s","<033>&a2500h+0V")
  writefile(l_dec,"%s","Wind Excluded: ")

  If cppfarmmisc:wind_exclusion > 0 then
    {
      Writefile(l_dec,"%s","Y")
    }
  else
    {
      Writefile(l_dec,"%s","N")
    }

  if cppfarmmisc:limit <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Limit: ",str(cppfarmmisc:Limit,"ZZ,ZZZ,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }

  if cppfarmmisc:rate <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a2500h+0V")
      writefile(l_dec,"%s%n","Rate: ",cppfarmmisc:Rate)
    }

  if cppfarmmisc:premium <> 0 then
    {
      Writefile(l_dec,"%s","<033>&a300h+120V")
      writefile(l_dec,"%s%s","Premium: ",str(cppfarmmisc:premium,"Z,ZZZ.99"))
l_line_counter = l_line_counter + 1
    }
  next cppfarmmisc
}
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1
