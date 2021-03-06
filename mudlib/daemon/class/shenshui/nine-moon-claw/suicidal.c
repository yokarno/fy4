#include <ansi.h>
inherit SSERVER; 
int perform(object me, object target)
{
    string msg;
    int skill_bonus, myexp;
    if(me->query("class")!="shenshui")
        return notify_fail("只有神水宫弟子才能使出「唯我独尊」的绝技。\n"); 
    if( !target ) target = offensive_target(me); 
    if( !target||!target->is_character()||!me->is_fighting(target) )
        return notify_fail("「唯我独尊」只能对战斗中的对手使用。\n"); 
    msg = RED "$N双目尽赤，祭出九阴白骨爪最后一式「唯我独尊」，";
    
    if ( me->query_skill_mapped("force") == "nine-moon-force") {
        skill_bonus = (int) me->query_skill("nine-moon-force" ,1) 
                     +(int) me->query_skill("nine-moon-claw" ,1);
                        
    }
    skill_bonus = (skill_bonus>=40) ? skill_bonus/40 : 1 ;
    
    myexp = (int) me->query("combat_exp");
   
    if( random(skill_bonus*myexp) + myexp * 9/10 >
        (int)target->query("combat_exp") )
    {
        msg += "结果$p被$N攻了个措手不及！\n" NOR;
        target->receive_damage("kee",(int) me->query("max_kee"),me);
        target->receive_wound("kee", ((int) me->query("max_kee")-20),me);
    }
    else msg += "可是$p还是躲过了$N的最后一击！！\n" NOR; 
    message_vision(msg, me, target);
    me->unconcious();
    return 1;
}  
