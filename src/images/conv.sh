convert pepperoni.gif -crop 24x16+0+0 top-bun0_xpm.xpm
convert pepperoni.gif -crop 24x16+24+0 top-bun1_xpm.xpm
convert pepperoni.gif -crop 24x16+48+0 top-bun2_xpm.xpm
convert pepperoni.gif -crop 24x16+72+0 top-bun3_xpm.xpm
sed 's/static char/static const char/' top-bun0.xpm > top-bun0_xpm.xpm
sed 's/static char/static const char/' top-bun1.xpm > top-bun1_xpm.xpm
sed 's/static char/static const char/' top-bun2.xpm > top-bun2_xpm.xpm
sed 's/static char/static const char/' top-bun3.xpm > top-bun3_xpm.xpm
mv top-bun0_xpm.xpm top-bun0.xpm 
mv top-bun1_xpm.xpm top-bun1.xpm 
mv top-bun2_xpm.xpm top-bun2.xpm 
mv top-bun3_xpm.xpm top-bun3.xpm 

convert basil.gif -crop 24x16+0+0 lettuce0_xpm.xpm
convert basil.gif -crop 24x16+24+0 lettuce1_xpm.xpm
convert basil.gif -crop 24x16+48+0 lettuce2_xpm.xpm
convert basil.gif -crop 24x16+72+0 lettuce3_xpm.xpm
sed 's/static char/static const char/' lettuce0.xpm > lettuce0_xpm.xpm
sed 's/static char/static const char/' lettuce1.xpm > lettuce1_xpm.xpm
sed 's/static char/static const char/' lettuce2.xpm > lettuce2_xpm.xpm
sed 's/static char/static const char/' lettuce3.xpm > lettuce3_xpm.xpm
mv lettuce0_xpm.xpm lettuce0.xpm 
mv lettuce1_xpm.xpm lettuce1.xpm 
mv lettuce2_xpm.xpm lettuce2.xpm 
mv lettuce3_xpm.xpm lettuce3.xpm 


convert tomatosauce.gif -crop 24x16+0+0 meat0_xpm.xpm
convert tomatosauce.gif -crop 24x16+24+0 meat1_xpm.xpm
convert tomatosauce.gif -crop 24x16+48+0 meat2_xpm.xpm
convert tomatosauce.gif -crop 24x16+72+0 meat3_xpm.xpm
sed 's/static char/static const char/' meat0.xpm > meat0_xpm.xpm
sed 's/static char/static const char/' meat1.xpm > meat1_xpm.xpm
sed 's/static char/static const char/' meat2.xpm > meat2_xpm.xpm
sed 's/static char/static const char/' meat3.xpm > meat3_xpm.xpm
mv meat0_xpm.xpm meat0.xpm 
mv meat1_xpm.xpm meat1.xpm 
mv meat2_xpm.xpm meat2.xpm 
mv meat3_xpm.xpm meat3.xpm 

convert dough.gif -crop 24x16+0+0 bottom-bun0_xpm.xpm
convert dough.gif -crop 24x16+24+0  bottom-bun1_xpm.xpm
convert dough.gif -crop 24x16+48+0 bottom-bun2_xpm.xpm
convert dough.gif -crop 24x16+72+0 bottom-bun3_xpm.xpm
sed 's/static char/static const char/' bottom-bun0.xpm > bottom-bun0_xpm.xpm
sed 's/static char/static const char/' bottom-bun1.xpm > bottom-bun1_xpm.xpm
sed 's/static char/static const char/' bottom-bun2.xpm > bottom-bun2_xpm.xpm
sed 's/static char/static const char/' bottom-bun3.xpm > bottom-bun3_xpm.xpm
mv bottom-bun0_xpm.xpm bottom-bun0.xpm
mv bottom-bun1_xpm.xpm bottom-bun1.xpm
mv bottom-bun2_xpm.xpm bottom-bun2.xpm
mv bottom-bun3_xpm.xpm bottom-bun3.xpm


