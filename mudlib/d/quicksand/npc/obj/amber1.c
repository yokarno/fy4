#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIY"����"NOR, ({"amber", "hupo"}) );
        set_weight(20);
        if( clonep() )
          set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long", "һ����Ө��͸�����귢�������Ļ�ɫ��\n");
            set("value", 5000000);
        }
        ::init_item();
}         
