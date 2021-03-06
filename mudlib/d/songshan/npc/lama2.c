 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        set_name("金伯胜夷", ({ "jin bo"}) );
        set("gender", "男性" );
        set("title",HIY"恒河三佛"NOR);
        set("age", 70+random(10));
        set("class","lama");        
        set("long",
                "天竺高僧，此次聚众到少林寺,妄图一统武林。\n"
                );
        set("class","lama");
        set("combat_exp", 4000000);
        set("score", 900);
        set("reward_npc", 1);
        set("difficulty",5);
        set("cor",40);
        set("cps",30);
        set("str",40);
        
        set("force",1000);
        set("max_force",1000);
        set("force_factor",110);
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);
                
        set("no_busy",4);
        set("resistance/kee",50);
        set("resistance/gin",random(80));
        set("resistance/sen",50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "金伯胜夷说：嘿嘿，其实恒河只是条小河，咱们兄弟总想若是能改成‘黄河三佛’
那可真有意思！\n",
                }) );
        
        set_skill("iron-cloth", 200);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("yue-strike", 170);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("jin-gang",200);
        set_skill("perception",200);
        
        map_skill("iron-cloth","jin-gang");
        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "yue-strike");
        map_skill("force", "bolomiduo");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) ); 
        setup();
        carry_object(__DIR__"obj/lamacloth1")->wear();
        carry_object(__DIR__"obj/ring2")->wear();
        
} 
smart_fight()
{
        int j,i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        
        for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie() && random(2))
                {       who->cast_spell("ni");
                        return;
                }               
        }
        return;
}  
void win_enemy(object loser)
{
        say("金伯胜夷哈哈一笑说道：好说，好说。\n"); 
} 
void lose_enemy( object winner)
{
        object gweapon;
        say("\n金伯胜夷大惊失色道：厉害，厉害！！！\n\n");
        message_vision(CYN"$N狞笑着说，不过你没机会告诉别人了！！\n",this_object());
        this_object()->kill_ob(winner);
} 
void die()
{
        object me;
        if(objectp(me=query_temp("last_damage_from") ))
        if(!me->query("marks/番僧2") && me->query("class")=="legend")
        {
                me->set("marks/番僧2",1);
        }
        ::die();
} 
