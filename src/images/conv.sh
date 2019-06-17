convert pepperoni.gif -crop 24x16+0+0 top-bun0_xpm.xpm
convert pepperoni.gif -crop 24x16+24+0 top-bun1_xpm.xpm
convert pepperoni.gif -crop 24x16+48+0 top-bun2_xpm.xpm
convert pepperoni.gif -crop 24x16+72+0 top-bun3_xpm.xpm
sed 's/static char/static const char/' top-bun0_xpm.xpm > top-bun0.xpm
sed 's/static char/static const char/' top-bun1_xpm.xpm > top-bun1.xpm
sed 's/static char/static const char/' top-bun2_xpm.xpm > top-bun2.xpm
sed 's/static char/static const char/' top-bun3_xpm.xpm > top-bun3.xpm
rm top-bun0_xpm.xpm
rm top-bun1_xpm.xpm
rm top-bun2_xpm.xpm
rm top-bun3_xpm.xpm

convert basil.gif -crop 24x16+0+0 lettuce0_xpm.xpm
convert basil.gif -crop 24x16+24+0 lettuce1_xpm.xpm
convert basil.gif -crop 24x16+48+0 lettuce2_xpm.xpm
convert basil.gif -crop 24x16+72+0 lettuce3_xpm.xpm
sed 's/static char/static const char/' lettuce0_xpm.xpm > lettuce0.xpm
sed 's/static char/static const char/' lettuce1_xpm.xpm > lettuce1.xpm
sed 's/static char/static const char/' lettuce2_xpm.xpm > lettuce2.xpm
sed 's/static char/static const char/' lettuce3_xpm.xpm > lettuce3.xpm
rm lettuce0_xpm.xpm
rm lettuce1_xpm.xpm
rm lettuce2_xpm.xpm
rm lettuce3_xpm.xpm


convert tomatosauce.gif -crop 24x16+0+0 meat0_xpm.xpm
convert tomatosauce.gif -crop 24x16+24+0 meat1_xpm.xpm
convert tomatosauce.gif -crop 24x16+48+0 meat2_xpm.xpm
convert tomatosauce.gif -crop 24x16+72+0 meat3_xpm.xpm
sed 's/static char/static const char/' meat0_xpm.xpm > meat0.xpm
sed 's/static char/static const char/' meat1_xpm.xpm > meat1.xpm
sed 's/static char/static const char/' meat2_xpm.xpm > meat2.xpm
sed 's/static char/static const char/' meat3_xpm.xpm > meat3.xpm
rm meat0_xpm.xpm
rm meat1_xpm.xpm
rm meat2_xpm.xpm
rm meat3_xpm.xpm

convert dough.gif -crop 24x16+0+0 bottom-bun0_xpm.xpm
convert dough.gif -crop 24x16+24+0  bottom-bun1_xpm.xpm
convert dough.gif -crop 24x16+48+0 bottom-bun2_xpm.xpm
convert dough.gif -crop 24x16+72+0 bottom-bun3_xpm.xpm
sed 's/static char/static const char/' bottom-bun0_xpm.xpm > bottom-bun0.xpm
sed 's/static char/static const char/' bottom-bun1_xpm.xpm > bottom-bun1.xpm
sed 's/static char/static const char/' bottom-bun2_xpm.xpm > bottom-bun2.xpm
sed 's/static char/static const char/' bottom-bun3_xpm.xpm > bottom-bun3.xpm
rm bottom-bun0_xpm.xpm
rm bottom-bun1_xpm.xpm
rm bottom-bun2_xpm.xpm
rm bottom-bun3_xpm.xpm
