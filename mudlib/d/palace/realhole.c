 inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����ʯ���У���������ȫ����ӭ�洵��һ�󺮷硣Խ�����ߺ�����ң�
��Х֮�������಻�����⺮��ĺ�Х������������ս���ϵ�ɱ¾֮��һ�㣬
ʹ������ɭ�İ��Ķ���֮�У������˿ֲ���ɱ����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"holeopen",
  "west" : __DIR__"interroad",
]));
        set("objects", ([
        __DIR__"obj/needle" : 1,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",190);
        set("coor/y",-40);
        set("coor/z",20);
        set("coor/x",190); 
        setup();
}
void reset(){
        object obj;
        
        ::reset();
        if(!present("needle", this_object())){
                obj = new(__DIR__"obj/needle");
                if(objectp(obj)){
                        obj->move(this_object());
                }
        }       
        return;
}      