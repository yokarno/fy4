#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("age",30+random(20));
//      set("attitude", "aggressive");
        set("combat_exp", 5000000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 1500);
        set("atman", 1500);
        set("max_mana", 1500);
        set("mana", 1500);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",60);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "СͷĿ�޺޵�˵�������ڽ����ϲ�������Ҳ�Ǹ����ϣ�������ֻ�ܿ��ţ�����������ң�\n",
        }) );
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,180,1,"/d/eren2/npc/obj/","all","all");
        set_name("������",({"tu jiaojiao"}));
           set("title",HIM"�����˲�����"NOR);
        set("long", "����һ�����˿��ڿ���СͷĿ����ֻ�۾������ɵؿ����㡣\n");
        
        setup();
        carry_object(__DIR__"obj/g_armor")->wear();
}         