 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int second_sword(object me,object target,int extra,int bonus,object weapon);
int perform(object me, object target)
{
        string msg;
        int extra, bonus, rsen;
        object weapon;

        extra = me->query_skill("qiuzhi-sword",1);
		bonus = me->query_skill("sword");
        weapon=me->query_temp("weapon");

        if ( extra < 50) return notify_fail("你的虬枝剑式还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［寒梅落］只能对战斗中的对手使用。\n");
        
        message_vision( HIC "\n$N手中"+weapon->name()+HIC"沿着一道奇古而又自然轨迹缓缓摆动，空气中忽然有一种清冽的感觉。\n"NOR, me);
        message_vision( WHT "一缕缕微寒的淡淡幽香似乎从虚无中幻出，若有若无。\n"NOR, me);
       
        if(random(me->query("combat_exp")+extra*extra*extra*3)>target->query("combat_exp")/2)
        {
                msg = HIG "$N"HIG"沉迷于淡淡的幽香中。\n"NOR;
				if(extra >= 100 && !target->is_busy()) {
					msg = HIG "$N"HIG"情不自禁地深深吸了一口气，陶醉于这淡淡的幽香中。\n"NOR;
					target->start_busy(2);
				}
				message_vision(msg, target);
				rsen = target->query("resistance/sen");
				target->set("resistance/sen",0);
                target->receive_damage("sen", extra +  random(bonus), me);
				if(me->query("class")=="mei" && extra >= 150) second_sword(me,target,extra,bonus,weapon);
				target->set("resistance/sen",rsen);
        }
        else
                message_vision(YEL "$N"NOR YEL"一凝神，不为缕缕幽香造成的幻像所动。\n"NOR,target); 

        if(me->query_busy()<2) me->start_busy(2);
        return 1;
        
} 

int second_sword(object me,object target,int extra,int bonus,object weapon)
{
        string msg;
        
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0;
		if(!present(weapon,me)||weapon->query("equipped")!="wielded") return 0;

        msg = HIW "\n点点光华漩然落下，似梅花又不是梅花，似雪花又不是雪花，飞向$n"HIW"周围。"NOR ;
		me->set_temp("hanmeiluo",1);
        me->add_temp("apply/attack", extra*3);    
        me->add_temp("apply/damage", bonus*5);          
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra*3);
        me->add_temp("apply/damage", -bonus*5);
		me->delete_temp("hanmeiluo");
		
        return 1;
}     
