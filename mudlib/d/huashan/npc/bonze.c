 // woodcutter.c
inherit NPC; 
void create()
{
        set_name("脚行僧", ({"bonze", "travel bonze"}) );
        set("gender", "男性" );
        set("age", 36);
        set("agi",25);
        set("per", 10);
        set("str",30);
        set("long",
                "一个游走四方的脚行僧。\n"
                );
        set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500);
        set("eff_gin", 500);
        set("eff_kee", 500);
        set("eff_sen", 500);
        set("gin", 500);
        set("kee", 500);
        set("sen", 500);
        set("combat_exp", 2000);
        set_skill("move", 50);
        set_skill("parry", 50);
            set_skill("dodge", 60);
            setup();
            carry_object(__DIR__"obj/cloth")->wear();  
                carry_object(__DIR__"obj/shoe1")->wear();
} 
