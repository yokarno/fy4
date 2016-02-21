 // icy_boot.c
#include <ansi.h>
#include <armor.h> 
inherit BOOTS; 
void create()
{
        set_name( HIC "觇玉软靴" NOR, ({ "jade-boots", "boots" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 8000);
                set("material", "cloth");
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

                set("armor_prop/armor", 1);
                set("armor_prop/dodge", 5);
        }
        ::init_boots();
}  
void owner_is_killed(object killer)
{
	if(objectp(killer))
        {
        message_vision("有样东西从尸体里跌落$N的怀中！\n\n",killer);
        this_object()->move(killer);}
        else
        {destruct(this_object()); }
}
