#include <ansi.h>
inherit NPC;
int answer_robery();
int answer_di();
int answer_yang();  
void create()
{
        set_name("应无物", ({ "ying wuwu","ying","wuwu" }) );
        set("long",
                "一个穿长衫的卖卜瞎子，从头发，脸色到衣服都是灰扑扑的颜色。\n"); 
        set("attitude", "friendly");
        set("age",49);
        set("str", 80);
        set("cor",80);
        set("agi",70);
        set("cps",65);
        set("con",80);
        set("nickname", HIG"瞽目神剑"NOR); 
        set("combat_exp", 2500000+random(2500000));
        set("max_force",3000);
         
        set_skill("unarmed",200);
        set_skill("sword",200);
        set_skill("softsword",200);
        set_skill("parry",700);
        set_skill("dodge",700);
        map_skill("sword","softsword"); 
/*        set("chat_chance", 1);
        set("chat_msg", ({
"花四爷凄惨的声音在你耳边回荡：“我死得好冤呐。。。”\n"
}) ); 
        set("inquiry", ([
                "劫镖案" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "杨铮" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "狄青麟" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ])); 
*/
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
} 
void heart_beat()
{
        ::heart_beat();
        if(query("sad_leave"))
                call_out("sad_leave",2);
} 
int do_busy(object who)
{
        object room,ying,yang,hook,sword;
        
        ying=this_object();
        room=environment(ying);
        if(!present(who,room)) return 0;
        if(who->query_skill("move",1)>99&&(hook=present("leave hook",who))&&(yang=present("yang zheng",room)))
        {
                message_vision(HIR"应无物如蝙蝠一般贴到$N身后，闪电般制住$N各处大穴，将$N随手一扔。\n"NOR,who);
                message_vision(HIM"但$N在倒下之前，用尽最后一丝气力，将离别钩扔给杨铮。\n"NOR,who);
                yang->set_temp("送离别钩的人",who);
                hook->move(yang);
                if(sword=present("sword",yang))
                        if(sword->query("equipped"))
                yang->ccommand("unwield sword");
                yang->ccommand("wield leave hook");
                message_vision(WHT"$N向$n颔首示意：“多谢这位"+RANK_D->query_respect(who)+"为我送来兵刃。”\n",yang,who);
        }
        else
        {
                message_vision(HIR"应无物如蝙蝠一般贴到$N身后，闪电般制住$N各处大穴，将$N随手一扔。\n"NOR,who);
                message_vision(HIR"应无物冷笑一声道：“杨铮，今日你死得可谓风光，又多了个人送你一程。”\n\n\n"NOR,who);
        }
        who->start_busy(100000);
        ying->set("busy_object",who);
        
} 
void sad_leave()
{
        message_vision("应无物长叹一声道：“纸刀传人终死于离别钩传人之手，时也？命也！”转身离去。\n",this_object());
        destruct(this_object());
}   
