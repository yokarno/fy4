#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"主人卧室"NOR);
        set("long", @LONG
这里是主人萧十一郎的卧房，一进此间，你顿时觉得四周寒气逼人，原来
房间里放置着一张寒冰玉床，据说此床非常神奇，睡(sleep)上去可以恢复心
神，这样的床江湖中仅存两张，另外一张在铁雪山庄；想来忘忧山庄的主人常
年在此练功，床的对面墙上画着一幅非常奇怪的壁画(picture)。
LONG
        );
        set("exits", ([ 
                    "west" : __DIR__"xiaolang_xiaodao5",
           ]));
        set("objects", ([
//                      __DIR__"npc/xiaolangwa" : 1,
                        ]) );
        set("item_desc", ([
                "bed": "一张寒冰玉床，睡上去可以恢复心神。\n",
                "床": "一张寒冰玉床，睡上去可以恢复心神。\n",
                "picture": HIC"五丈宽的墙壁上，画满了狼人。\n"+
HIC"各式各样的狼人，有的是半人半狼，有的是非人非狼，有的形式是人，却不是人，有的\n"+HIC"形状是狼，却偏偏有颗人心。\n"+
HIC"五丈宽墙，画的也许并没有十万狼人，却有只真正的狼。\n"+
HIY"血狼。\n"+
HIC"狼人们居然还有“手”，手里都有柄弯刀，刀锋上都在滴着血，滴成了这只血狼。\n"+
HIC"血狼背上有一对翅膀，翅膀一形成，它就飞向一个戴着紫金白玉冠的年轻人。\n"+
HIC"一个很英俊，很温和的年轻人---"+RED"萧十一郎。\n"+
HIC"狼人们却在向他膜拜，就像是最忠实的臣子在膜拜帝王。\n"+
HIC"难道“他”就是狼中之王？\n"+
HIC"难道看起来充满魔意的萧十一郎，就是狼王？\n"+
HIC"血狼也有它的臣子。\n"+
HIC"十叁只美丽的怪鸟，围绕这它，飞翔在它左右，有孔雀的翎，有蝙蝠的翅，有燕子的轻\n"+HIC"盈，又有蜜蜂的毒针。\n"+
HIC"——这就是狼奴？\n"NOR
        ]) );
        set("no_steal",1);
        set("coor/x",17);
        set("coor/y",2033);
        set("coor/z",30);
        //set("no_fight",1);
        setup();
} 
void init()
{
   add_action("do_sleep", "sleep");
}   
int do_sleep(string arg)
{
   object me, obj, girl;
   int gin, kee, sen; 
   me = this_player();
   obj = this_object(); 
   if (me->is_fighting()) return 1;
      message_vision(HIW"$N在寒冰床上躺了下来......"NOR, me);
      tell_object(me, HIW"慢慢地，你感到一股热气自丹田升起！。\n"NOR);
      message("vision", me->name()+HIW"慢慢地躺在床上，全身不断的冒着白气。\n"NOR, environment(me), me);
      gin = (int) me->query("eff_gin");
      kee = (int) me->query("eff_kee");
      sen = (int) me->query("eff_sen");
      me->set("gin", gin);
      me->set("kee", kee);
      me->set("sen", sen);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
      me->set_temp("is_unconcious",1);
      me->set("disable_type",HIG "<睡梦中>"NOR); 
      call_out("wake", 10, me);
      return 1;
  }   

void wake(object me)
{
   object obj; 
   obj = this_object();
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
   me->delete_temp("block_msg/all");
   me->delete_temp("is_unconcious");
   if(!me->is_ghost())
   message_vision(HIY"$N睁开了眼睛，一个鲤鱼打挺从床上跳了下来。\n"NOR, me); 
   tell_object(me, HIY"你觉得全身充满活力，似乎有使不完的劲。\n"NOR);
}   
