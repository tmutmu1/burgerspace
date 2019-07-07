convert dough2.gif -crop 24x32+0+0 bottom-bun0_xpm.xpm
convert dough2.gif -crop 24x32+24+0  bottom-bun1_xpm.xpm
convert dough2.gif -crop 24x32+48+0 bottom-bun2_xpm.xpm
convert dough2.gif -crop 24x32+72+0 bottom-bun3_xpm.xpm
sed 's/static char/static const char/' bottom-bun0_xpm.xpm > bottom-bun0.xpm
sed 's/static char/static const char/' bottom-bun1_xpm.xpm > bottom-bun1.xpm
sed 's/static char/static const char/' bottom-bun2_xpm.xpm > bottom-bun2.xpm
sed 's/static char/static const char/' bottom-bun3_xpm.xpm > bottom-bun3.xpm
rm bottom-bun0_xpm.xpm
rm bottom-bun1_xpm.xpm
rm bottom-bun2_xpm.xpm
rm bottom-bun3_xpm.xpm

convert tomatosauce2.gif -crop 24x32+0+0 meat0_xpm.xpm
convert tomatosauce2.gif -crop 24x32+24+0 meat1_xpm.xpm
convert tomatosauce2.gif -crop 24x32+48+0 meat2_xpm.xpm
convert tomatosauce2.gif -crop 24x32+72+0 meat3_xpm.xpm
sed 's/static char/static const char/' meat0_xpm.xpm > meat0.xpm
sed 's/static char/static const char/' meat1_xpm.xpm > meat1.xpm
sed 's/static char/static const char/' meat2_xpm.xpm > meat2.xpm
sed 's/static char/static const char/' meat3_xpm.xpm > meat3.xpm
rm meat0_xpm.xpm
rm meat1_xpm.xpm
rm meat2_xpm.xpm
rm meat3_xpm.xpm
