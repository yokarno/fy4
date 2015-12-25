#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "琴道");
        set("usage/magic", 1); 
        set("learn_bonus", -50);
        set("practice_bonus", -1000);
        set("black_white_ness", 120);
        set("effective_level", 180);
        set("skill_class", "baiyun");
        /*
        set("parry_msg", ({
        "$n左手拇指食指虚捻，右手轻挥，空气中骤生［变商］之音，一轮音波将$N迫开。\n",
        "$n两手凌空虚划，冷冽的气劲吹过，忽传［清徵］之音，$N不觉有点心神撼动。\n",
        "$n凝神专著，伸手轻抚，如拨琴弦，耳侧传来［正宫］之调，$N一时茫然不知所以。\n", 
        }) );
        set("unarmed_parry_msg", ({
        "$n左手拇指食指虚捻，右手轻挥，空气中骤生［变商］之音，一轮音波将$N迫开。\n",
        "$n两手凌空虚划，冷冽的气劲吹过，忽传［清角］之音，$N不觉有点心神撼动。\n",
        "$n凝神专著，伸手轻抚，如拨琴弦，耳侧传来［正宫］之调，$N一时茫然不知所以。\n", 
        }) );
        action = ({
        ([      "action":               "$N轮指急抚，阵阵疾风如珠玉落盘，激起［变羽］之音，袭向$n的$l",
                "dodge":                180,
                "parry":                20,
                "damage":               70,
                "damage_type":          "刺伤",
                "weapon":               "指风",
        ]),
        ([      "action":               "$N信手轻敲，［变角］声沉，周围忽起鼓点隆隆，如十面埋伏围向$n",
                "dodge":                140,
                "parry":                90,
                "damage":               20,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N左手凝气，右手横拉而过，［清商］之调如无边丝雨，漫漫飘向$n的$l",
                "dodge":                120,
                "parry":                120,
                "damage":               90,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N伸掌直拍，疾风忽起，流云四散，在气流波动的［正商］之音中，击向$n的$l",
                "dodge":                160,
                "parry":                20,
                "damage":               10,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手骤然下击，劲风带动忽发［变徵］之音，如凝易水之悲寒，直取$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        });
*/
}   
/*
mixed parry_ob(object victim, object me)
{       int busy_time;
        int skill;
        int my_exp, your_exp;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        
        skill=me->query_skill("chess",1);
        
        if (random(skill) + skill/3 > 100 && me->is_busy()) {
                message_vision(HIG"$N心神合一，琴弈相通，弈道的［得算篇］历历在目，身形骤然轻巧起来。\n"NOR, me);       
                me->stop_busy();
        }
        
        return 0;
}        
*/   
