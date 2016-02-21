 // Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("沙罗门", ({ "shaluomen" }) );
        set("gender", "男性" );
        set("age", 62);
        set("long","沙罗门来自天竺，生性寡僻，专门与动物为伍，擅长驯兽（ｔｒａｉｎ）。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "train"); 
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "沙罗门说道：这位" + RANK_D->query_respect(ob)
                                + "，回天竺怎么走？\n");
                        break;
                case 1:
                        say( "沙罗门叹道：这位" + RANK_D->query_respect(ob)
                                + "，我帮你驯兽，你指点一下我回家的路吧。\n");
                        break;
        }
} 
int do_train(string arg)
{
        object me,pet;
        int cost,gold;
        me = this_player();
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
        if(!arg) return notify_fail("沙罗门道：＂你要驯什么呀？＂\n");
        pet = present(arg,environment());
        if(!objectp(pet)) return notify_fail("沙罗门道：＂你要驯什么呀？＂\n");
        if(pet->query("possessed") != me )
        return notify_fail("沙罗门道：＂那好象不是你的吧？＂\n");
//okey we identified the target, now the cost:
        cost = (int) pet->query("obedience");
        cost *= cost;
	gold = (int)me->query("deposit")/10000;
        if(gold < cost)
        return notify_fail("你钱庄里不够"+chinese_number(cost)+"两金子。\n");
        if((int)me->query("score") < cost/10)
        return notify_fail("你的评价不够"+chinese_number(cost/10)+"点。\n");
        pet->add("obedience",1);
        pet->save();
        me->add("score",-cost/10);
        me->add("deposit", -cost*10000);
        me->save();
        command("say 好了！\n");
        tell_object(me,"沙罗门笑道：这次用掉你"+chinese_number(cost)+"两金子，我直接在你的钱庄划帐。\n");
        return 1;
}    
