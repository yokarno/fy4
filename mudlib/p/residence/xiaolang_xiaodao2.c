#include <ansi.h>
 inherit ROOM;
void create()
{
        set("short", HIG"梅园小道"NOR);
        set("long", @LONG
你漫步在这条碎石小路上，闻着花草的香味，这里的宁静安详让你暂时忘却了
江湖中的血雨腥风，你看到各种小鸟在花草树木中雀跃欢叫，时不时的还有各种小
动物在小路上来回穿梭。
LONG
        );
    set("exits", ([ 
								"south" : __DIR__"xiaolang_xiaodao",
                "north" : __DIR__"xiaolang_huayuan",
        ]));
    set("objects", ([

    ]));
    set("outdoors", "residence"); 
    set("coor/x",15);
    set("coor/y",2032);
    set("coor/z",30);
        setup();
} 
void init(){

        if(this_player()->query("marks/黄雀") && NATURE_D->is_day_time() 
                        && NATURE_D->get_weather() == "晴") {
                call_out("bird_come", 2, this_player());
        }
        if( this_player()->query_temp("know/zhuguo") ){
               add_action("do_east","east");
               }
}
void bird_come(object me){
        object obj;
        
        if(!interactive(me) || environment(me) != this_object()){
                return;
        }
//        obj = new("/d/wolfmount/npc/obj/zhuguo");
        if (random(10)>=5){
                message_vision("\n一只小黄雀飞落在$N面前飞来飞去，唧唧喳喳的叫个不停。\n", me);
      					tell_object(me, HIW"黄雀的腿上一条清晰的伤痕让你记起好像在哪里见过它。\n"NOR); 
      					tell_object(me, HIW"小黄雀不停的向着丛林的东方叫嚷着，\n似乎想让你跟着它过去。\n"NOR);
      					tell_object(me, HIW"你向小道东边的丛林仔细一看，发现了一条暗道。\n"NOR);
      					me->set_temp("know/zhuguo",1);
//                obj->move(me);
        }
        me->delete("marks/黄雀");
}  
int do_east(){
        object room;
        object me=this_player();
        
        if( me->query_temp("know/zhuguo") ) {
                message("vision", me->name()+"伸手把灌木丛分开，一头钻了进去。\n", 
                                environment(me), me);   
                room = find_object(__DIR__"xiaolang_guanmu");
                if(!objectp(room)){
                        room = load_object(__DIR__"xiaolang_guanmu");
           }
                me->move(room);
                me->delete_temp("know/zhuguo");
                message("vision", me->name()+"从丛林之中钻了出来。\n", environment(me), me);
                return 1;
        }
        return 0;
}     
