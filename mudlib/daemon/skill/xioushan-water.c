 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without 
// the written permission from authors. 
inherit SKILL; 
void setup(){ 
        set("name", "秀山引水功"); 
        set("usage/unarmed", 1); 
        set("usage/parry", 1);   
        set("effective_level", 190); 
        set("practice_bonus", -5); 
        set("skill_class", "quanli"); 
         
        set("parry_msg", ({ 
                "$n打出水浪将$N逼得连退几步。\n", 
        }) ); 
 
        set("unarmed_parry_msg", ({ 
        "$n手中一道水花封向$N。\n", 
        }) ); 
        action = ({ 
                ([      "action":               "$N袖中水浪袭向$n的$l", 
                        "force":                400, 
                        "damage":               200, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N一招[水中望月]，浊焚流向$n的$l", 
                        "damage":               200, 
                        "force":                300, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N象污水中的黑汁，忽聚忽散出掌击向$n的$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "瘀伤" 
                ]), 
                ([      "action":               "$N打出水花散向$n的$l", 
                        "force":                100, 
                        "damage":               200, 
                        "damage_type":  "瘀伤" 
                ]), 
           ([      "action":               "$N聚起全身的功力，双手打出青水飞向$n", 
                        "force":                200, 
                        "damage":               200, 
                        "damage_type":  "瘀伤" 
                ]), 
        }); 
} 
int valid_learn(object me) 
{ 
        if( (int)me->query_skill("wuchenforce", 1) < 120 ){ 
            return notify_fail("你的内功心法火候不足，无法练秀山引水功。\n"); 
        } 
        if(!::valid_learn(me)){ 
                return 0; 
        } 
        return 1; 
}  
