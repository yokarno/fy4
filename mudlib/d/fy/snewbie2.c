 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @long
���������һƬ����Ǭˬ��������Ȼ�������˰��˺ܶණ����������Ȼ��
�úܿ��������ϻ���һЩʪ�����Ľ�ӡ����Ȼ��������������żȻ��������һ
����Ӱ��Ҳ�����û̿֡������ƺ��Ե��ϵı��ﲢ��̰����ֻȡȥ�Լ����裬
�������뿪��
long
        );
        set("exits", ([ /* sizeof() == 4 */
"out" : __DIR__"snewbie1",
  "enter" : __DIR__"snewbie3",
  
]));
        set("objects", ([
               
"/d/guanwai/npc/obj/redcloth3":1,
"/d/fy/npc/obj/kiujia":1,
"/d/songshan/npc/obj/ring1":1,
"/d/songshan/npc/obj/ring2":1,
"/d/songshan/npc/obj/ring3":1,
                
                        ]) );
        set("indoors", "fengyun");
                set("no_fight",1);

        set("coor/x",0);
        set("coor/y",-40);
        set("coor/z",-10);
        
        setup();
}