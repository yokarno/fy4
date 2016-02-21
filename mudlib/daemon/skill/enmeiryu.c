 //enmeiryu.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "½��Բ����ȭ��");
        set("usage/unarmed", 1);
        set("practice_damage", 60);
        set("effective_level", 170);
        set("learn_bonus", -300);
        set("practice_bonus", -100);
        set("black_white_ness", -10);
        set("skill_class", "ninja");
        set("parry_msg", ({
                "$nһ�ѵ�ס$N�������������һ�ƣ���$N����˦�˳�ȥ��������������\n",
                "$n��$N����ʱ������һ��������ͻȻʹ��һ�С���������һͷײ��$N�Ķ��\n",
        "$N�ۿ���Ҫ������$n��һ˲�䣬$nһ�С����������һԾ����������һ�С� \n",
        "$n����$N�����ļ�϶��ͻȻ�۽���һȭ����$N�����ţ��á����䡹��������һ�С� \n",
        "$nͻȻ��ָ����$N��˫�ۣ�$N����֮��ֻ��ֹͣ����������һ�С�ָ������ \n",
        "$nһ����Һ����$N���۾���һ�С���ϼ�������$N�Ĺ����� \n", 
        }) );
        set("unarmed_parry_msg", ({
                "$nһ�ѵ�ס$N�������������һ�ƣ���$N����˦�˳�ȥ��������������\n",
                "$n��$N����ʱ������һ��������ͻȻʹ��һ�С���������һͷײ��$N�Ķ��\n",
        "$N�ۿ���Ҫ������$n��һ˲�䣬$nһ�С����������һԾ����������һ�С� \n",
        "$n����$N�����ļ�϶��ͻȻ�۽���һȭ����$N�����ţ��á����䡹��������һ�С� \n",
        "$nͻȻ��ָ����$N��˫�ۣ�$N����֮��ֻ��ֹͣ����������һ�С�ָ������ \n",
        "$nһ����Һ����$N���۾���һ�С���ϼ�������$N�Ĺ����� \n",
        }) );
        action = ({
        ([      "action":               
"$Nһ�С���ն������$n��$l�� ",
                "dodge":                90,
                "parry":                70,
                "damage":                50,
                "damage_type":  "����",
                "name":         "��ն",
        ]),
        ([      "action":               
"$N�Ƶ��۽�$n��˫ȭ����$n���·��ϣ�������һ�С����h���� ",
                "dodge":                50,
                "parry":                70,
                "damage":                300,
                "damage_type":  "����",
                "name":         "���h",
                
        ]),
        ([      "action":               
"$Nһ�С����ߡ�����$n�����ڲ࣬������̤ǰһ�����ⲿ��������$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "����",
                "name":         "����",
        ]),
        ([      "action":               
"$Nһ�С�˷�⡹����ȭ��$n����ȭ�ܿ�������ͻȻ����$n��$l�� ",
                "dodge":                10,
                "parry":                50,
                "damage":                120,
                "damage_type":  "����",
                "name":         "˷��",
        ]),
        ([      "action":               
"$N���һ�������¡�������ͻȻ���һ��������֧�أ�$n������ԥ֮�䣬
$N�������ѵ�������$n��$l�� ",
                "dodge":                20,
                "parry":                100,
                "damage":                80,
                "damage_type":  "����",
                "name":         "����",
        ]),
        ([      "action":           
"$Nʹ����һ�С���������˫�־�ס$n���½󣬵�ϥ����$n��$l�� ",
                "dodge":                80,
                "parry":                10,
                "damage":                270,
                "damage_type":  "����",
                "name":         "����",
        ]),     
        ([      "action":           
"$N���һ��ʹ��һ�С����ơ���ͻȻ����$n��������һ������������֧�أ� 
˫���Ƽ��������$n�ľ����� ",
                "dodge":                20,
                "parry":                30,
                "damage":                470,
                "damage_type":  "����",
                "name":         "����",
        ]),            
        ([      "action":           
"$Nһ��ת������������$n�����ţ�$n�����мܣ�$NͻȻ���С��ϵ硹��
��$n��С���� ",
                "dodge":                150,
                "parry":                10,
                "damage":                100,
                "damage_type":  "����",
                "name":         "�ϵ�",
        ]),                    
    
        });
}  
int practice_skill(object me)
{
        return notify_fail("½��Բ����ȭ��ֻ����ѧ�ġ�\n");
}   
int valid_learn(object me)
{
        object ob;
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if (!me->query("tianfeng/done_quest"))
                return notify_fail("���ʮ����δ��Ӧת���������书��\n");
        if ((int)me->query("tianfeng/enmeiryu")!=1){
                return notify_fail("���ʮ����δ��Ӧ���������书��\n");
        }
        return 1;
}      