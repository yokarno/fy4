 // mind_sense.c
#include <ansi.h>
inherit SSERVER; 
int conjure(object me, object target)
{
        string msg;
        int damage, ap, dp; 
        if(me->query("class")!="bonze")
                return notify_fail("只有兴国禅寺的弟子才可以使用神识神通！\n"); 
        if((int)me->query_skill("essencemagic",1) < 40)
                return notify_fail("你的法术不够高！\n");
               
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这种法术只能对战斗中的对手使用。\n"); 
        if((int)me->query("atman") < 80 )
                return notify_fail("你的法力不够！\n"); 
        me->add("atman",-80);
        
        msg = HIC "$N闭目凝神，印堂发出一道金芒射向$n！\n\n" NOR;
        //  400*3= 1200, total damage 1200 +random(1200)
        damage = me->query_skill("magic")*3;
        dp = target->query("combat_exp");
        ap = me->query("combat_exp");
        
        if( random(ap *3 )+ap/2 > dp ) {
                damage = damage + random(damage);
                msg +=  HIY "金芒从$p"+HIY"身上透体而过，拖出一条长长的青气直射到两三丈外的地下！\n" NOR;
                target->receive_damage("gin", damage, me);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,damage);
        } else
                {       msg += HIB"但是被$n"HIB"躲开了。\n\n"NOR;
                        message_vision(msg, me, target);
                        }
        if (me->query_busy()<2) me->start_busy(2);
        
   return 1;
}     
