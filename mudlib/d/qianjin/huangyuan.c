#include <ansi.h>
inherit ROOM;
void warning(object me);
void capture(object me);
void create()
{
        set("short", "荒园");
        set("long", @LONG
转过荷花荡，景色倏然一变，雾色凄迷，寒鸦掠过，小路上荒草没径，荷塘里
也落满了枯叶。尽头的枯木林中小楼一角，依稀就是当年小李探花读书学剑的冷香
小筑，如今却早已荒废，爬满了蛛网积尘。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"hehuadang2",
]));
        set("outdoors","qianjin"); 
        set("coor/x",-60);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
        //replace_program(ROOM);
}
void init()
{
        object me = this_player();
        
        add_action("do_search","search");
        
        remove_call_out("warning");
        remove_call_out("capture");
        if (me->query_per() > 26 
                && me->query("age") >13 
//        && !NATURE_D->is_day_time()
                && me->query("age") <26 
                && !me->query_temp("afei_on_the_way")
                && me->query("combat_exp")>300000 
                && me->query("gender") == "女性" ) 
        {
                call_out("warning", 10, me);
   }
        
}
void warning(object me) {
        if (environment(me) == this_object() ) {
        tell_object(me, WHT"\n荒园里寒鸦凄厉，落叶疏萧，一种危险的预感让你觉得非常不安。\n\n"NOR);
                call_out("capture", 5, me);
        }
        
} 
void capture(object me) {
        object room;
        if (environment(me) == this_object() ) { 
        message_vision(HIB"\n枯木林中忽然卷起一阵阴冷的风，寒飕飕的自你脸上刮过。你霎了霎眼，突然觉得\n"NOR, me);
        message_vision(HIB"似乎有个阴影站在$N的身后。$N悚然一惊，正想转身，却已被点中了穴道。\n\n阴影将$N挟在肘下，腾云驾雾般的掠了出去．．．\n\n"NOR, me);
                room=find_object(AREA_QIANJIN"basement");
                if(!objectp(room))
                        room=load_object(AREA_QIANJIN"basement");
                me->set_temp("marks/meihuadao", 1);
                me->move(room);         
             message_vision(HIR"\n梅花盗将$N丢到了地下室角落里的小床上，一阵莫可名状的气味袭来，$N气息一\n窒，晕了过去。\n"NOR,me);
             me->unconcious();
        }
} 
int do_search() {
        object me = this_player(); 
        if (me->query_temp("afei_on_the_way") ) {
                tell_object(me, WHT"\n荒园里寒鸦凄厉，落叶疏萧，一种危险的预感让你觉得非常不安。\n\n"NOR);
                
                message_vision("$N拨开枯叶，发现地面有一个洞口。\n", me);
                if( !query("exits/down") ) {
                        set("exits/down", __DIR__"basement");
                        call_out("close_path", 1);                
                        
                }
                return 1;
        }
        return 0;
}  
void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"一阵风吹起片片枯叶，纷纷扬扬地落下，遮蔽了地上的洞口。\n",
                this_object() );
                delete("exits/down");
}   
