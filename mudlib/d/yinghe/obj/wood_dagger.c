 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIG"叠翠匕首"NOR, ({ "wood dagger", "dagger" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "不知用何物造成的匕首，刀身微微透着绿芒。\n");
                set("wield_msg", "$N从怀中摸出一把明晃晃的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n收入怀中。\n");
                set("attribute", "wood");
                set("yinghe_weapon", 1);
        }
        ::init_dagger(90);
}     
