#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"神兵谱"NOR, ({ "shenbingpu" }) );
    set_weight(5);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "卷");
            set("material", "skin");
            set("long", "一卷泛黄的册子，里面绘制了海内十三件神兵图案，而卷首上书五个大字：\n\n"NOR
+HIC"                              海内神兵录\n\n"NOR
+CYN" 【大风刀】        －塞外奇兵，三十余年前札木合凭此纵横大漠。\n"NOR
+YEL" 【出跸刀】        －一把美奂美仑的魔刀，雕有美人出跸图，端是巧夺天工。\n"NOR
+BLU" 【搏浪锤】        －昔年义士以之搏杀暴君嬴政，千古壮士，豪气如昨。\n"NOR
+RED" 【护花铃】        －惊虹击电一金铃，铃声一振一消魂，江湖中闻之丧胆的奇门兵刃。\n"NOR 
+WHT" 【苍穹神剑】      －集天地之精华，吸日月之灵气。一把神奇的剑，一段神奇的故事。\n"NOR
+RED" 【沥泉神枪】      －一代名将岳飞之物，沙场血战，直捣黄龙，为天下英雄所景仰。\n"NOR
+CYN" 【圆月弯刀】      －天上只有一轮明月，地上也只有这一把弯刀。明月圆，刀光现。\n"NOR
+YEL" 【菩提法杖】      －万载菩提木所制，坚逾金钢，可避百邪，据传乃是佛祖圣物。\n"NOR
+WHT" 【冰魄寒霜剑】    －万载玄冰凝成的一把冰剑，晶莹透彻，彻骨之寒。\n"NOR
+CYN" 【流星蝴蝶剑】    －一把普通的剑，但她那永恒的美丽，她那一瞬的辉煌，却是无与伦比的。\n"NOR
+GRN" 【碧血照丹青】    －上古神剑，十万神魔因惧怕其无边的神力，便加恶咒于其。\n"NOR
+YEL" 【盘古开天斧】    －盘古开天辟地的神斧，凝聚了九天十地的力量，但至今无人堪破其中奥秘。\n"NOR
+BLK" 【九现神龙鬼见愁】－金龙九现，妙用无方，昔年一代奇人欧阳亭以之叱咤武林，鬼神莫测。 \n\n"NOR);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_put", 1);

          } 
    ::init_item();
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
