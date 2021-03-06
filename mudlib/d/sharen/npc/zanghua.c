 // waiter.c
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("姬葬花", ({ "ji zanghua" }) );
        set("gender", "男性" );
        set("age", 45);
        set("title",RED  "杀人庄主"NOR);
        set("long",
                "一个不足五尺的侏儒，却是现在杀人庄的庄主。
有人说他是白痴，有人说他是嗜杀如狂的凶手，但这些人都莫名奇妙地消失了。\n");
        set("combat_exp", 50000000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 100);
        set("per",3);
        set("fle",50);
        set("dur",50);
        set("con",50);

        


        set_skill("dodge",250);
        set_skill("chaos-steps",250);
        set_skill("perception",250);        
        set_skill("qiankunstrike",250);        
        set_skill("unarmed",250);
        map_skill("unarmed","qiankunstrike");
        map_skill("dodge","chaos-steps");

        set("force",40000);
        set("max_force",40000);
        set("max_mana",40000);
        set("max_atman",40000);
        set("force_factor",150);

        setup();
        carry_object(__DIR__"obj/birdbox");
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
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
message_vision("$N向着$n喃喃自语：杀人者死，被杀者死，杀人者被杀，被杀者杀人。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N对$n像白痴一样傻笑：我可是最珍惜生命的人了。。。\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N望了$n一眼：好材料，好一副被杀的材料。\n",this_object(),ob);
                        break;
        }
}
