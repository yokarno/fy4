 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "内院门");
        set("long", @LONG
这是面并不高大的墙，闻得此门之后便是少林后院，也就是天下武学
的发源地--少林武院。墙前站着几个少林武僧，手持戒刀，纹丝不动地注
视着前方。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"neiyuan",
  "southup" : __DIR__"qianfe",
]));
        set("objects", ([
                __DIR__"npc/monk8" : 2,
       ]) );
        set("outdoors", "shaolin");
        set("coor/x",-210);
        set("coor/y",290);
        set("coor/z",60);
        setup();
}
int valid_leave(object me, string dir)
{
        object ob;
        
if( userp(me) &&
dir=="north" && ob=present("shaolin monk", this_object())
&& me->query("vendetta/shaolin")>=1)
return notify_fail("和尚喝道:贼子止步!\n");
        
if( userp(me) &&
dir=="north" && ob=present("shaolin monk", this_object()) &&
(me->query("family/generation") > 22  ||
me->query("family/family_name") != "少林寺"))
return notify_fail(
"和尚说道：只有少林寺入室弟子才可以进入少林内院。\n");
return 1;
} 
void reset()
{
object *inv, ob;
string *sname=({"地普","地单",});
int i;
::reset();
ob=present("shaolin monk", this_object());
if(ob) ob->set("name","地普");
if(ob) ob->set("chat_chance_combat",50);
inv = all_inventory();
if(ob)
{
ob->dismiss_team();
for(i=0;i<sizeof(inv);i++)
        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
        if(i<=1) {
        ob->add_team_member(inv[i]);
        inv[i]->set("name",sname[i]);
        }
}
}     
