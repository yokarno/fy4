 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("石观音", ({ "shi guanyin","guanyin" }) );
    set("nickname", HIG"芳华永驻"NOR );
    set("gender", "女性" );
    set("age", 25);
    set("int", 30);
    set("str",60);
    set("per", 30);
    set("agi",100);
    set("apprentice_available", 50);
    set("ranks",({"弟子","小魔","少魔","大魔","奇魔","长老","元老","副掌门"}));
    set("rank_nogen",1);
    set("fly_target",1);
    set("long",
        "石观音的美丽，竟已是今人不能想象的，因为她的美丽已全部占据了
人们的想象力。有很多人都常用“星眸”来形容女子的美丽，但星光又怎
及她这双眼睛的明亮与温柔。有很多人都常用“春山”来形容美女的眉，
但纵是雾里朦胧的春山也不及她秀眉的婉约。
"
        );
    set("force_factor", 400);
    set("chat_chance", 1);
    set("chat_msg", ({
        "石观音道：“你......你不觉我老？”\n",
            "石观音笑了笑，又道：“你可知道这里是什么地方？”\n",
            "石观音眼光突然朦胧，柔声道：“你既知道，为何还不过来？”\n",
            }) ); 
    set("max_gin", 3000);
    set("max_kee", 3000);
    set("max_sen", 3000);
    set("eff_gin", 3000);
    set("eff_kee", 3000);
    set("eff_sen", 3000);
    set("gin", 3000);
    set("kee", 3000);
    set("sen", 3000);
    set("max_atman", 300);
    set("atman", 300);
    set("max_force", 3000);
    set("force", 3000);
    set("max_mana", 300);
    set("mana", 300);
    set("agi",25);
    set("int",30);
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yaozhan" :),
            }) );
    set("combat_exp", 99999999);
    set("inquiry", ([
        "无花" : (: kill_him :),
        "李姑娘" : (: kill_him :),
        "李菊" : (: kill_him :),
        "天枫十四郎" : (: kill_him :),
        "南宫灵" : (: kill_him :), 
        ]));
    set_skill("unarmed", 100);
    set_skill("blade", 150);
    set_skill("charm", 200);
    set_skill("force", 100);
    set_skill("parry", 100);
    set_skill("literate", 100);
    set_skill("dodge", 100); 
    set_skill("kongshoudao", 100);
    set_skill("wind-blade", 130);
    set_skill("ghosty-force", 300);
    set_skill("ghosty-steps", 100); 
    map_skill("unarmed", "kongshoudao");
    map_skill("blade", "wind-blade");
    map_skill("force", "ghosty-force");
    map_skill("parry", "wind-blade");
    map_skill("dodge", "ghosty-steps"); 
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本掌门今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
                command("smile");
                command("say 你日后可要多多努力！");
                command("smile");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bandit");
        add("apprentice_availavble", -1);
}  
int kill_him()
{
        object me;
        me = this_player();
        command("say 看来你已经知道我的来历了！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
int accept_object(object who, object ob)
{
   
        if(ob->query("name")!="乌鞘长刀") return 0;
        if(!who->query("天枫_quest3"))
        {
                message_vision("石观音皱了皱眉：你这把刀是哪里来的。。。？\n",who);
                return 0;
        }
        message_vision("石观音抽出长刀，凝神伫立半晌，脸色变幻不停，似乎苍老了许多。。。\n",who);
        call_out("give_saki",5,who);
        return 1;
} 
int give_saki(object who)
{
        object saki;
                
        if(environment(who)!=environment()) return 0;
    message_vision(HIY"石观音突然嫣然一笑道：一夜夫妻百日恩，唉，就劳烦这位"+ RANK_D->query_respect(who) +"把这瓶清酒
送于他，就算奴家报答当日情了。\n"NOR,who);
        saki=new(__DIR__"obj/saki");
        saki->move(who);
        who->set("天枫_quest4","成功");
        
        return 1;
}     
