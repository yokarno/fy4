 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(WHT"白云熊胆丸"NOR,({"baiyun wan","wan"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "江湖中盛传的疗伤圣药，但价格昂贵，普通人只能望洋兴叹。\n");
        set("unit","颗");
        set("value", 150000);
        }
        ::init_item();
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{
        int value = 20;
        int diff; 
        if(this_player()->is_fighting())
            return notify_fail("战斗中不能用药！！\n");
        if(this_player()->is_ghost()){
                return notify_fail("鬼魂不可以用药。\n");
        }
        diff = this_player()->query("max_kee")-this_player()->query("eff_kee");
        if(!(diff))    return notify_fail("你没有受伤！\n");
    if(value < diff) value = diff;
            
    message_vision("$N咽下一颗白云熊胆丸，伤口神奇般愈合了起来。。。\n",this_player());
        this_player()->add("eff_kee",value);
        destruct(this_object());
        return 1;
}    
