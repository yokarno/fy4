 // drift_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        
        if(me->query("class")!="bonze")
                return notify_fail("只有兴国禅寺的弟子才可以使用游识神通！\n");
        
        if((int) me->query_skill("essencemagic",1) < 60)
                return notify_fail("你的八识神通不够高深！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中无法使用游识神通！\n");
        if( me->query("atman") < 300 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 100 )
                return notify_fail("你的精不够！\n");
        if( me->is_ghost())
                return notify_fail("鬼魂无法使用游识神通！\n");  
        if( me->query("have_mission") )
                return notify_fail("有组织任务在身，不能使用游识神通！\n");  
        if( me->query("mission_over") )
                return notify_fail("你只能用修仙术返回组织领取奖励。\n");    
        if( target )
                return notify_fail("游识神通只能对自己使用！\n");
        write("你要移动到哪一个人身边？");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
} 
void select_target(object me, string name)
{
        object ob; 
        if( !name || name=="" ) {
                write("中止施法。\n");
                return;
        } 
        ob = find_living(name);
        if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)
        || !ob->query("max_atman") || !ob->query("atman") ||userp(ob)
// the following check start/arrival room.      
        || environment(ob)->query("no_death_penalty")
        || environment(me)->query("no_fly")
        || environment(ob)->query("no_fly")
// the following is the NEW FLY FLAG, all NPCs are non-driftable by default.    
   || !ob->query("fly_target")
        ) {
                write("你无法感受到这个人的灵力 ....\n");
                write("你要移动到哪一个人身边？");
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
        
        if( me->is_fighting() ) {
                write("战斗中无法使用游识神通！\n");
                return;
        } else if( me->query("atman") < 100 ) {
                write("你的灵力不够！\n");
                return;
        } 
        me->add("atman", -100);
        me->receive_damage("gin", 50);
        
        message_vision( HIY "$N低头闭目，开始施展游识神通 ....\n" NOR, me);
        
        if( random(ob->query("max_atman")) < (int)me->query("atman")/5) {
                write("你感受到对方的灵力，但是不够强烈。\n");
                return;
        }
        
        if( random(80) > me->query_skill("essencemagic",1)){
                write("你因为不够熟练而失败了。\n");
                return;
        }
        
        if(environment(ob)->query("no_magic")||environment(ob)->query("no_fly")) {
                write("你想要游识的地方不可以用神通！\n");
                return;
        }
        
        message( "vision", HIY "\n一道耀眼的光芒忽然罩住" + me->name() 
                + "，几秒钟後，光芒和人一齐消失得无影无踪！\n\n" NOR, environment(me), ({ me }) );
        me->move(environment(ob));
        message( "vision", HIY "\n你的眼前突然出现一团耀眼的光芒，光芒中浮现出一个人影！\n\n" NOR,
                environment(ob), ({ me }) );
}        
