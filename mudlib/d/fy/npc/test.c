#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("试验品", ({ "tester" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "一个为生活而终日奔波的小商人．\n");
          set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
}  
void die(){
    object killer;
    string location;
    int difficulty;     
    location="菜市口";
    
    killer = this_object()->query_temp("last_damage_from");
         
    if(!killer->query("m_killer/tester")&& !this_object()->is_ghost()) {
         killer->set("m_killer/tester",1);
         difficulty =1;
         this_object()->master_reward(this_object(),killer,location,difficulty);
        }
        
    ::die();
} 
void master_reward(object victim, object killer, string location, int difficulty)
{
    object money_reward;
    int i, pot, combat_exp, score;
    string reward_msg,kill_msg;    
    string *kill_type = ({ "击杀", "刺杀", "搏杀", "击毙","狙杀" });
    reward_msg="";
    
    kill_msg= kill_type[random(5)];
    
    if (killer->query("combat_exp")>victim->query("combat_exp")/50) {
        
        pot = difficulty*200;
        combat_exp = difficulty*20000;
        score = difficulty*50;
    
        killer->add("potential",pot);
        killer->add("combat_exp", combat_exp);
        killer->add("score", score);
        for(i=0; i<difficulty+1; i++) {
        money_reward = new("/obj/money/tenthousand-cash");
        money_reward ->move(killer);
        }
        
        CHANNEL_D->do_sys_channel(
        "info",sprintf("%s，%s于%s%s%s。", NATURE_D->game_time(),
                killer->name(), location, kill_msg, this_object()->name()) );  
        reward_msg +=HIW+"你成功地杀死了一个风云天骄，你被奖励了：\n\t\t" +
        chinese_number(combat_exp) + "点实战经验\n\t\t"+
        chinese_number(pot) + "点潜能\n\t\t" +
        chinese_number(score) + "点评价\n\t\t" + 
        chinese_number(difficulty+1) + "万两银子\n" + NOR;
                
        tell_object(killer,reward_msg); 
        } 
}        
