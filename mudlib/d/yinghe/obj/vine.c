#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
        set_name(MAG"聆风紫藤"NOR, ({ "purple vine", "vine" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","紫色的藤条闪着神秘的色彩。。\n");
                set("unit", "捆");
                set("base_unit", "根");
                set("base_weight", 10000);
                set("base_value", 10);
        }
        set_amount(1);
    ::init_item();
}       
