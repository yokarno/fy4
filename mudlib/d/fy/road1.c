 inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
һ��С·�������������졣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ�߾�
�Ǹߴ�ķ��Ƴǳ�ǽ�ˡ���������Կ�����ǽ��ֵ�ڵ�ʿ����վ�ڡ��ӵ��ϳ���
���̲ݡ�΢�������һ�ɵ���������Ϣ���Դӽ�Ǯ���ڷ��Ƴ��������Ժ�����
�����˽����Ķ���������ÿ���峿���н�ʨ�ھֵĳ��ӴӴ�·����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "south" :"/d/quicksand/huangyie0",
        "south" : __DIR__"fywest",
  "northeast" : __DIR__"road2",
]));
         set("objects", ([
        __DIR__"/d/fycycle/obj/grass" : 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",-160);
        set("coor/y",50);
        set("coor/z",0);  
        setup();
} 
void reset()
{
object con, item, *inv;
::reset();
if( con = present("grass",this_object()))
if( inv = all_inventory(con))
if( !sizeof(inv))
        {
        item = new(__DIR__"obj/quant");
        item->move(con);
        }       
}    