 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int orforce; 
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ն��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        extra = me->query_skill("kongshoudao") ;
        if(extra < 100 ) return notify_fail("��ģۿ��ֵ��ݲ���������\n");
        me->add("force_factor",extra/4); 
        orforce = (int) me->query("force"); 
        me->add("force",extra/3*10); 
        msg = HIR "$NͻȻ�Ƶ�$n������ϥ��Ȼ�϶���˫��ͬʱץ��$n����ͼ��$n�ĺ����Ķϣ�" NOR;
        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->set("force_factor",0); 
        me->set("force", orforce); 
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
        me->start_busy(2);
        return 1;
}     