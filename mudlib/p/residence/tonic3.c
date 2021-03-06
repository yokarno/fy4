 // a skeleton for user rooms
#include <ansi.h>
#define X_COOR 10
#define Y_COOR 2060
#define Z_COOR 50
#define R_FLAG 2561
#define OWNER "tonic"
#define CLASS "财神庙"
inherit ROOM;
void create()
{
set("short", "路边");
set("long", @long
那条小河名叫凤河，那无边无际的葡萄架，一直伸延到目光的尽
头。果园的色彩依然斑斓，田野中的尚没褪尽的绿色、黄色、紫色……
使人产生了走进画中的美感。路边一棵通天的大树直插入云，看不到树
顶，你很想跳（jumpto）上去看看。
long
);
        set("exits", ([
"south" : __DIR__"tonic2",

]));   
set("objects", ([
       ]) );
        set("coor/x",X_COOR);
        set("coor/y",Y_COOR);
        set("coor/z",Z_COOR);
        set("outdoors","residence");
        set("room_flag",R_FLAG);
        set("owner", OWNER);
   set("class", CLASS);
        setup();
}
void init()
{
        int flag;
        flag = (int) query("room_flag");
        if(flag & 1) set("valid_startroom",1);
        if(flag & 2) set("NONPC",1);
        if(flag & 4) set("no_fight",1);
        if(flag & 8) set("no_magic",1);
        if(flag & 16) set("outdoors","residence");
        add_action("do_invite","invite");
        add_action("do_setowner","setowner");
        add_action("do_list","list");
        add_action("climbing", "jumpto");

}
int valid_enter(object me)
{
        int flag;
// means no enter at the beginning.
        int enter = 0;
    flag = (int) query("room_flag");
// always let owner go in:
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 16)
        enter = 1;
        if(flag & 512)
        if((string)me->query("id") == (string)query("owner"))
        enter = 1;
        if(flag & 1024)
        if((string)me->query("class") == (string)query("class"))
        enter = 1;
        if(flag & 2048) 
        {
                if(strlen(query("invite")) && strsrch((string)query("invite"),"["+(string)me->query("id")+"]") != -1)
                enter = 1;
        }
//      write(sprintf("%d", enter));    
        return enter;
}
int do_list()
{
        object me;
        string *list,invitelist;
        me = this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        invitelist = query("invite");
        if (strlen(invitelist))
        {
                list = explode("]"+invitelist+"[", "][");
                write("你邀请了下列玩家到你的房间:\n");
                for(int i=0;i<sizeof(list);i++)
                        write(list[i]+"\n");
        }else
                write("你没有邀请任何人到你的房间。\n");
        return 1;
} 
int do_invite(string arg)
{
        object me;
        string invitelist;
        me= this_player();
        if((string)me->query("id") != (string)query("owner"))
        return 0;
        if( !arg )
        {
                write("你要邀请谁? \n");
                return 1;
        }
        invitelist = (string)query("invite");
        if(strlen(invitelist) && strsrch(invitelist,"["+arg+"]") != -1)
        {
                //if the person has already been invited, remove it from invite list.
                invitelist = replace_string(invitelist,"["+arg+"]","");
                set("invite",invitelist);
                write("你将"+arg+"从你的邀请名单中除去。\n");
        }else
        {
           //invite the person.
                if( find_player(arg))
                {
                        if(!strlen(invitelist))
                                set("invite","["+arg+"]");
                        else
                                set("invite",invitelist+"["+arg+"]");
                        write("你邀请"+arg+"来你的房间。\n");
                }else
                {
                        write("咦... 有这个人吗?\n");
                }
        }
        return 1;
} 
int do_setowner(string arg)
{
        string oldowner;
        oldowner = (string)query("owner");
        set("owner",arg);
        write("你将房间的主人暂时设为"+arg+"。\n");
        call_out("set_back",60, oldowner);
        return 1;
} 
int set_back(string oldowner)
{
        set("owner", oldowner);
        return 1;
}

int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                return 0;
        }
        if( arg == "tree" || arg == "大树" || arg == "树")
        {
        me = this_player();
        message_vision("$N一脚踏上突出的树枝，身形交错地顺着树杆升了上去。\n", me);
        me->start_busy(3);
        call_out("fliping",3,me);
        me->stop_busy();
        return 1;
        }
        else
        {
                write("你不可以攀"+arg+"\n");
                return 1;
        }
}
int fliping(object me)
{
        if(!interactive(me) || environment(me) != this_object()){
                return 1;
        }
        if(objectp(me) && !me->is_ghost()){
        me->move(__DIR__"tonic4");
        message_vision("$N顺着树杆跳了上来。\n", me);
        }
        return 1;
}      