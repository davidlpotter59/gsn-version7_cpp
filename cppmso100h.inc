/* cppmso100h.inc  
   scips.com
   August 23, 2007
   Farmowners worksheet
*/

unsigned ascii number l_line_counter=1 ;
unsigned ascii number l_max_lines=40 ;

writefile(l_dec,"%s",l_arial)
access cppfarmliab,
   set cppfarmliab:policy_no = cppfarm:policy_no, generic

access cppfarmsupp,
   set cppfarmsupp:policy_no = cppfarm:policy_no, generic

Writefile(l_dec,"%s","<033>&a300h+120V")
writefile(l_dec,"%s%n","Group No: ",cppfarmliab:group_no)
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","Class Code: ",cppfarmliab:class_code)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 2

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Prem/Ops Exposure: ",cppfarmliab:exposure[1])
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Exposure Base: ",cppfarmliab:exposure_base[1])
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Per: ",cppfarmliab:rates_per[1])
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","Rate: ",cppfarmliab:base_rate[1])
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Products Exposure: ",cppfarmliab:exposure[2])
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Exposure Base: ",cppfarmliab:exposure_base[2])
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Per: ",cppfarmliab:rates_per[2])
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%n","Rate: ",cppfarmliab:base_rate[2])
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%n","Limits Table: ",cppfarmliab:limits_table)
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+120V")
writefile(l_dec,"%s%s","Agricultural Equip:  ",str(cppfarmsupp:agric_equip_limit,"ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Pollution:  ",str(cppfarmsupp:pollution_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Building Code:  ",str(cppfarmsupp:building_code_percent,"ZZZ%"))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Light/Power:  ",str(cppfarmsupp:light_power_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s","Building Code ACV Basis:  ")

if cppfarmsupp:building_code_acv_basis > 0 then
  {
    writefile(l_dec,"%s","Y")
  }
else
  {
    writefile(l_dec,"%s","N")
  }
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%S","Contract Carrier:  ",str(cppfarmsupp:contract_carrier_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Loss Utility:  ",str(cppfarmsupp:loss_utility_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Campers:  ",str(cppfarmsupp:campers_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Mechanical:  ",str(cppfarmsupp:mechanical_limit,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Furs: ",str(cppfarmsupp:furs_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Credit Card:  ",str(cppfarmsupp:credit_card_limit,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Grave Markers: ",str(cppFARMsupp:grave_markers_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Debris: ",str(cppfarmsupp:debris_limit,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Guns: ",str(cppfarmsupp:guns_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Loss Of Use: ",str(cppFARMsupp:loss_use_limit,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Jewelry: ",str(cppFARMsupp:jewelry_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Extra Expense: ",str(cppfarmsupp:extra_exp_limit,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Money: ",str(cppFARMsupp:money_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Operations: ",str(cppfarmsupp:operations_limit,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Business Property: ",str(cppfarmsupp:bus_prop_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Rental Property: ",str(cppfarmsupp:rental_prop_limit,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Watercraft: ",str(cppfarmsupp:watercraft_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Securities: ",str(cppfarmsupp:securities_limit,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s","Boilers:  ")

if cppfarmsupp:boiler > 0 then
  {
    writefile(l_dec,"%s","Y ")
  }
else
  {
    writefile(l_dec,"%s","N")
  }

writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s%s","Silverware: ",str(cppfarmsupp:silverware_limit,"ZZ,ZZZ,ZZZ.99"))
Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s%s","Water Damage: ",str(cppfarmsupp:water_damage_limit,"ZZ,ZZZ,ZZZ.99"))
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1

Writefile(l_dec,"%s","<033>&a300h+0V")
writefile(l_dec,"%s","Inflation Guard:")
Writefile(l_dec,"%s","<033>&a1100h+0V")
writefile(l_dec,"%s%n","Coverage A: ",cppfarmsupp:inflation_guard[1])

Writefile(l_dec,"%s","<033>&a2500h+0V")
writefile(l_dec,"%s","Peak Season: ")
Writefile(l_dec,"%s","<033>&a3300h+0V")
writefile(l_dec,"%s%s","Coverage D: ",str(cppfarmsupp:peak_season[1],"999"))

Writefile(l_dec,"%s","<033>&a1100h+120V")
writefile(l_dec,"%s%n","Coverage B: ",cppfarmsupp:inflation_guard[2])

Writefile(l_dec,"%s","<033>&a3300h+0V")
writefile(l_dec,"%s%s","Coverage E: ",str(cppfarmsupp:peak_season[2],"999"))

Writefile(l_dec,"%s","<033>&a1100h+120V")
writefile(l_dec,"%s%n","Coverage C: ",cppfarmsupp:inflation_guard[3])
Writefile(l_dec,"%s","<033>&a1100h+120V")
writefile(l_dec,"%s%n","Coverage D: ",cppfarmsupp:inflation_guard[4])
Writefile(l_dec,"%s","<033>&a1100h+120V")
writefile(l_dec,"%s%n","Coverage E: ",cppfarmsupp:inflation_guard[5])
writefile(l_dec,"%s","<NL>")
l_line_counter = l_line_counter + 1
