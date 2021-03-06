 inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();
void smart_fight(); 
void create()
{
        set_name("王震湘", ({ "wang zhenxiang" }) );
        set("gender", "男性");
        set("age", 55);
        set("long",
"太湖二十四舵的总舵把子王震湘王老爷子。\n"
);
        set("inquiry", ([
            "俞独鹤" : (: kill_him :),
             "俞放鹤" : (: fanghe :),
              "俞佩玉" : (: peiyu :),
   ]));
                        
        set("chat_chance", 1);
        set("chat_msg", ({
                "王震湘笑道：“先天无极门的威名，岂是你这小辈可以想象的！”\n",
                "王震湘道：好地方呀好地方！\n",
        }) );
          
        set("attitude", "friendly");
        set("title","太湖王");
        set("nickname", HIG"水上大豪"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",5);
        set("class","yinshi");
        set("fly_target",1);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
        set("combat_exp", 4000000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        set("str",36);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 100);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );        
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
        set_skill("whip",200);        
        set_skill("qidaoforce", 150);
        set_skill("five-steps",180);
        set_skill("thunderwhip",180);
        set_skill("pofeng-strike",180);
                
        map_skill("unarmed","pofeng-strike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        map_skill("whip","thunderwhip");
        map_skill("parry","thunderwhip");
        
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(3));
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/w_whip")->wield();
} 
 
int kill_him()
{
        object me;
        me = this_player();
        command("say 看来你知道得真不少！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
int fanghe()
{
    command( "say 放鹤兄是我先天无极门的掌门人。");     
    return 1;
}  
int peiyu()
{
    command ("say 这小子是我义兄不成材的儿子。");
    return 1;
}   
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1 && enemy[1]->is_zombie()) {
                who->perform_action("whip.zombie-wp1");
                return;
        }
        who->perform_action("whip.tianleiyiji"); 
        return;
}  
