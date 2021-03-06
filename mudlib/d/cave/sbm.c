 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "西北门");
        set("long", @LONG
一道石拱门，上面长满了青苔，滑不留手。拱门的右边
有一块钟乳石，上面用碳黑写着一些奇怪的符号。门并不很
高，稍微高一些的人需要弯腰才可以通过。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"tsbd",
  "west" : __DIR__"sbj",
]));
        set("objects", ([
     __DIR__"obj/stone": 1,
                        ]) );
        set("indoors", "cave");
        set("coor/x",-55);
        set("coor/y",-0);
        set("coor/z",-20);
        setup();
} 
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "west" && !obj->query("vendetta/authority")){
                if (present("killer d", this_object()))
                {
                        another = present("killer d", this_object());
                        return notify_fail(another->name()+"闪身挡住了你的路。\n");
                } else if (random(10)>6) {
                        another = new(__DIR__"npc/killer_d");
                        another->move(environment(obj));
                        message_vision(HIB"路边黑影一闪!\n"NOR, obj);   
                   return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
                }
        }       
        return 1;
}
