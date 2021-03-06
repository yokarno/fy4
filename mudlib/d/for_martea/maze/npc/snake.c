 inherit NPC;
void use_poison(); 
void create()
{
        set_name("青蛇", ({ "snake" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一条全身碧绿的毒蛇。\n");
        set("limbs", ({ "头部", "身体", "尾巴", "七寸" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        
        set("max_kee",2400);
        set("max_gin",1800);
        set("max_sen",1800);
        
        set("death_msg",          "青蛇痛苦地扭动了几下，全身软软地散了开来。\n\n"  );
        set("leave_msg",          "嗖地一声钻了出去"                     );
        set("arrive_msg",         "蜿蜒地游了过来"                              );
        set("fleeout_message",    "嗖地一声，往$d钻了出去"                      );
        set("fleein_message",     "缓缓地游了过来，软耷耷地在地上趴着。\n"          );
        
        
        set("combat_exp", 1200000);
        set("bellicosity", 300 );
        set_skill("dodge", 200);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup(); 
} 
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob,"你觉得腿上剧痛，伸手一摸发现两个毒牙印痕。\n");
                ob->receive_wound("kee",40);
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(3)+3);
}      
