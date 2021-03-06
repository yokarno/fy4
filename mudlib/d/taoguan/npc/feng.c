 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("风道人", ({ "taoist feng" }) );
        set("nickname",HIW "怒斧" NOR);
        set("gender", "男性");
        set("age", 60);
        set("long",
"风道人是丁氏兄妹新近从南疆请来的三清宫四供奉之一。\n"
);
        set("attitude", "friendly");
        set("combat_exp", 600000);
        set("score", 2000);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("class", "knight"); 
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
//      set("pursuer", 1); 
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 30); 
        set("atman", 150);
        set("max_atman", 150); 
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5); 
        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("gouyee", 100);
        set_skill("axe",100);
        set_skill("xuanyuan-axe",90);
        set_skill("windy-steps",120);
        set_skill("taoism", 100);
        set_skill("necromancy", 100);    
        set_skill("flame-strike",100);
        map_skill("unarmed", "flame-strike");
        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        map_skill("axe","xuanyuan-axe");
        map_skill("dodge","windy-steps");
        map_skill("parry","xuanyuan-axe");
        map_skill("move","notracesnow");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();
        add_money("coin", 30);
        carry_object(__DIR__"obj/f_axe")->wield();
        carry_object(__DIR__"obj/f_cloth")->wear();
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{
    object player, victim;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        if(victim->query("name")=="看风景的道姑" 
          && victim->query("id")=="wandering taoist" )
        {
            message_vision(HIW"$N对著$n喝道：大胆，是何居心!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp")) {
//                              ccommand("say I will perform fengliu");
                                this_object()->smart_busy();
                        }
                        if (enemy[i]->is_busy()) {
//                              ccommand("smug");
                                this_object()->smart_attack();
                        } else ccommand("pig");
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.fengliu");
}
smart_attack() {
   this_object()->perform_action("axe.guifushengong");     
        }        
