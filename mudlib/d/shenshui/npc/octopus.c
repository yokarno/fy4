#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";  
int strangle();
int slash();
int bite();
int octopus_attack(); 
void create()
{
        set_name("大章鱼" , ({ "octopus" }) );
        set("title", HIW "千年巨怪"NOR);
        set("race", "野兽");
        set("age", 10000);
        set("long", "这是一条身躯巨大的章鱼，长八米。它那海色的呆呆的巨大眼睛盯视着你。它
的八只胳膊，不如说八只脚，长在它脑袋上，有它身躯的双倍那么长，伸缩摆
动，象疯妇人的头发那样乱飘。这怪东西的嘴——骨质的嘴，生成象鹦鹉的一
样——垂直的或开或合。它的骨质的舌头本身有几排尖利的牙，颤抖着露出那
一幅真正的大铁钳。 在软体上有一个鸟嘴!它的身躯作纺锤形，中腰膨胀，形
成一大肉块，重量不下二万至二万五千斤。它身上的不定的颜色随着这怪东西
的激动，极端迅速的改变着，从灰白色陆续变为红褐色。\n");
        
        set("combat_exp", 5000000);
        
        set("str", 90);
        set("cor", 100);
        set("cps", 30);
        set("dur", 30);
        set("agi", 30);
        set("boss",1);
        set("max_gin",50000);
        set("max_kee",200000);
        set("max_sen",50000);
        set_skill("move",3000);
        
        set("no_curse",1);
        set("resistance/kee",50);
        
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite"}) );
        
        
           set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                30:     (: octopus_attack() :),
        ]) );           
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: bite()  :),     
        }) );
        
        set("chat_chance",1);
        set("chat_msg",({
                "大章鱼那死鱼一般的眼睛盯着你，使你不寒而栗。\n",
        }) );  
        
        set_temp("apply/attack", 600);
        set_temp("apply/armor",  200);
        set_temp("apply/dodge",  450);
        set_temp("apply/damage", 50);
        setup();
        if (!random(2)) carry_object(__DIR__"obj/claw");
        if (!random(200)) carry_object(__DIR__"obj/pearl2");
} 
int octopus_attack() {
        
        if(time()-query("bite_time")<4) return 1;
        switch (random(2)) {
                case 0: strangle();break;
                case 1: slash();break;
        }
        return 1;
}  
int strangle(){
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        enemy=ob->query_enemy();
        for (i=0;i<6;i++){
                me=enemy[random(sizeof(enemy))];
           if (!me->is_busy()) break;
        }
        if (me->is_busy()) return 1;
        
        message_vision(HIW"\n$N的触手忽然间张开，八条辐射线从有两只眼睛的一张脸上射了出来，
像一张巨网将$n死死缠住。\n"NOR,ob,me);
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
}
         
int slash () {
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        enemy=ob->query_enemy();
                
        message_vision(HIM"\n$N的身体忽然变成紫色，随即喷出一股紫雾，雾中八条触手上下翻飞，
击向在场的每一个人。\n"NOR,ob); 
        for (i=0;i<sizeof(enemy);i++) {
                tell_object(enemy[i],HIB"你觉得恶臭扑面，头晕目眩。\n"NOR);
                enemy[i]->receive_damage("sen",300,ob);
                if (!userp(enemy[i])) enemy[i]->receive_damage("sen",300,ob);
                COMBAT_D->report_status(enemy[i]);
        }       
        if (ob->query_busy()<2) ob->start_busy(1);
        return 1;
}  
int bite() {
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        ob->set("bite_time",time());
        enemy=ob->query_enemy();
        me=enemy[random(sizeof(enemy))];
        message_vision(HIR"\n$N的脑袋像陀螺一般旋转着，忽然间张开血盆大嘴，一口向$n咬去。\n"NOR,ob,me);
        me->receive_wound("kee",1000,ob);
        COMBAT_D->report_status(me);
        if (ob->query_busy()<3) ob->start_busy(2);
   return 1;
}  
void die()
{
        object rstone, me,owner,money_reward;
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        environment(this_object())->set("octopus_death",time());
        
        if(objectp(me)) { 
                if(!me->query("m_killer/大章鱼")){
                        CHANNEL_D->do_sys_channel("info",sprintf("%s，%s于%s%s%s。", NATURE_D->game_time(),
                                me->query("name"), environment(this_object())->query("short"),"斩杀", name())); 
                        me->set("m_killer/大章鱼",1);
                        me->add("score",100);
                        me->add("combat_exp",10000);
                        me->add("potential", 2000);
                        money_reward = new("/obj/money/gold");
                        money_reward->set_amount(100);
                        money_reward ->move(me);
                        tell_object(me,WHT"恭喜你杀死了大章鱼，你被奖励了!!!\n"NOR);
                }
        } 
        ::die();
}  
