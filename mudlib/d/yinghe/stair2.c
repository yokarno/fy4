 // Copyright (C) 2002, by neon. All rights reserved by Fengyun Workshop.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ʯ����");
        set("long", @LONG
������Ľ�ʯ�������£�û������ĺڰ��С�Խ�����ߣ�����������
Խ�̹ǡ���Ȼ�з��ڴ�������Ȼ�о���Χ�ĺڰ���������һ��������
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"stair1",
  "down" : __DIR__"stair3",
  ]));
        set("objects", ([
                __DIR__"npc/soulbat" : 2,
        ]));      
        set("indoors", "yinghe");
    set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",-40);
        setup();
        replace_program(ROOM);
} 