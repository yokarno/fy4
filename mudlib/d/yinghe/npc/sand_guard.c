#include <ansi.h>
inherit NPC;
void use_poison();
void sonic_attack();
void create()
{
    set_name(HIY"金麟异兽"NOR, ({ "sand guardian" }) );
//      set_title("荧河守护武士");
    set("age", 400);
    set("long", "金色的麟加上头上的角，像极了传说中的麒麟。\n");
    set("attitude", "heroism");
    set_skill("dodge", 250+random(100));
    set_skill("move", 450+random(200));
    set("combat_exp", 1000000+random(2000000));
        set("bellicosity", 300);
        set("invisibility",1);
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
//            (: sonic_attack :),
    }) ); 
    setup();
} 
/*void sonic_attack() {
        object *enemy, ob;
        string msg;
        int number_enemy, bat_exp;
        enemy = query_enemy();
        bat_exp = 1000000 + random((int) query("combat_exp"));
        number_enemy = sizeof(enemy); 
                        
        while(number_enemy--) {
                if( enemy[number_enemy] && living(enemy[number_enemy]) ) {
                        kill_ob(enemy[number_enemy]);
                        if( userp(enemy[number_enemy]) ) enemy[number_enemy]->fight_ob(this_object());
                        else enemy[number_enemy]->kill_ob(this_object()); 
                        if( bat_exp > (int)enemy[number_enemy]->query("combat_exp") ) {
                                tell_object(enemy[number_enemy],RED"尖锐的叫声如无数钢针从四面刺来，你觉得浑身锥心裂骨般的疼痛！\n"NOR);
                                enemy[number_enemy]->revieve_damage(kee, 1000+random(1000), this_object());
                                enemy[number_enemy]->revieve_wound(sen, 700+random(1000), this_object());
                                COMBAT_D->report_status(enemy[number_enemy],1);
                   }
                }
        }
        start_busy(3);
}*/ 
