 // SILENCER@FY4 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小石洞");
        set("long",  @LONG
说是石洞，其实只是石壁上一块凹进的地方，洞里黑咕隆咚地伸手不见五指。
顶壁上不停地有水珠渗出，滴在颈中透心地凉。脚下踩到几块硬硬的东西，顺着
摸下去，竟似是一具骷髅，偶尔会有几只蝙蝠扑闪着翅膀飞过，漆黑，压抑，使
人忍不住地想大声呼叫。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"yongdao2",
        ]));
        set("objects", ([
                __DIR__"obj/woodbarrel" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_scream", "scream");
        add_action("do_scream", "cry");
        add_action("do_scream", "jiao");
} 
int do_scream()
{
        object room, guard, me;
        me = this_player();
        if (guard=present("guardian",this_object()))
                return notify_fail("噤声，面前就有敌人！\n");
        remove_call_out("summon_guard");
//      call_out("summon_guard",3);
        me->start_busy(2);
   message_vision("\n$N禁不住心中的恐慌，失声惊叫起来。。。啊，啊，啊啊啊。。。\n",me);
        message_vision("叫声在洞壁中回荡，远远地传了出去。\n\n"NOR,me);
        return 1;
} 
summon_guard() {
        
        object guard,room;
        
        room=find_object(AREA_EREN2"yongdao3");
        if(!objectp(room)) 
                room = load_object(AREA_EREN2"yongdao3"); 
        guard=present("guardian",room);
        
        if(!guard) {
                room=find_object(AREA_EREN2"yongdao3a");
                if(!objectp(room)) 
                        room = load_object(AREA_EREN2"yongdao3a"); 
                guard=present("guardian",room);
        }
        
        if (guard && !guard->is_fighting()) {
                guard->move(this_object());
                message("vision","未几，一个黑影闪了过来。\n",this_object());
                message("vision",guard->query("name")+"喝道:“什么人！！“\n",this_object());
        } else 
                message("vision","许久许久，一点动静也没有。\n",this_object());
}        
        
                 
              
