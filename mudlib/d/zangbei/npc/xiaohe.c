#include <ansi.h>
inherit "/d/taiping/npc/smart_npc"; 
void create()
{
        set_name("С��",({"xiao he","xiaohe"}));
        set("title",HIR"����� ɱ��"NOR);
        set("long","
С��Ư���ü����Ѳ����Ǹ����ˡ����ϴ�˵С�����Ǵ���Ů�˵��·�����
ͷ������������������˶��ض��ᱻ����ȥ���ǡ�����������Ƥ������ֱ��
Ů�˻�ϸ���ף��ܶ��˶��������������������շ�ɳ�г�����ˣ���ô����
��ô�׵�Ƥ���������۾�ȴһֱ����ô��������ô������\n"); 
        set("gender","����");
        set("group","khlr");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",5500000);  
        set("attitude", "aggressive");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "*":    "�ϻ���˵����������",
        ]));
        
        set("nb_chat_chance", 100);
           set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
        }) );                   
        
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","sharen-sword",1);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
 
}      