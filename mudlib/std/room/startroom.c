#include <ansi.h>
inherit ROOM; 
int good_luck(object me);
int newbie_help(object me);
void init(){
        object me;
        me = this_player();
        if(interactive(me) && me->query_temp("first_time_login")) {
                call_out("newbie_help", 1, me);
        }
        add_action("do_answer", "answer");
} 
int newbie_help(object me){
        tell_object(me, HIY"һ����͵Ĺ�Ʈ������Ȧ���Ǹ���˫��ɫ����С���\n"NOR);
        tell_object(me, "ֻ��С����Ц��ӯӯ��˵��������ӭ�����������磡��λ" 
                        + RANK_D->query_respect(me) + "\n"NOR);
        tell_object(me, "�Ƿ���Ҫ��������һ�������������� ��answer yes/no��\n");
        me->delete_temp("first_time_login");
        me->set("marks/newbie_intro", 1); 
} 
int do_answer(string arg){
        object me;
        
        me = this_player();
        if(!me->query("marks/newbie_intro")){
                return 1;
        }
        if(!arg) {
                tell_object(me, "��ش�answer yes/no����\n");
        } else if(arg == "yes") {
                if(me->query("marks/newbie_intro") == 1){
                        tell_object(me, "\nС�����������㽲��������\n"); 
                        tell_object(me, "�����ֳ���է������Ҫ��Ϥ�����ͻ������������ſ��Խ�����ȥ��\n"); 
                        tell_object(me, "��˵˵�������������ʲô�������ô�Ҷ�֪�������� new ���\n"); 
                        tell_object(me, "\n���磺" + HIG"new ��Һã�\n"NOR); 
                        me->ccommand("new ��Һã�");      
                        tell_object(me, "\n�����ֻ�������ǰ����˵ʲô���������ô�Ҷ�֪����������\n"); 
                        tell_object(me, "say ���\n\n���磺" + HIG"say С�������ã�\n"NOR);      
                        tell_object(me, "\nС��������˵��������������£���ҵľ����������ǲ������ĵġ�\n"); 
                        tell_object(me, "Ҫ��ʳ�����ˮ�����䡣�����������Ҫ���⣬Ī����ѧ��Ժ��ˡ���\n"); 
                   tell_object(me, "С��������Ц�ţ�����ʵ�����Ӥ��Ҫѧ��Ժ���һ���ġ�Ҫ��\n"); 
                        tell_object(me, "Ҫ����ϸ�̸����أ��� ��answer yes/no��\n"); 
                        me->add("marks/newbie_intro", 1);
                } else if(me->query("marks/newbie_intro") == 2) {
                        tell_object(me, "\nС����˵�������ðɣ�һ����ҵ�����״̬�ã飬��𣬺ͣ�����\n");
                        tell_object(me, "�Ϳ�ȫ����ʾ������\n");
                        tell_object(me, "�����ǣ飨����������������������һ�����̣���ס����Ʒ��ʾ�㴩��\n");
                        tell_object(me, "������ס����Ʒ��\n");
                        me->ccommand("inventory");
                        tell_object(me, "�����ǣ��\n");
                        me->ccommand("hp");
                        tell_object(me, "���������������ῴ����\n");
                        me->ccommand("score");
                        tell_object(me, "��ʳ�����ˮ���٣������Ҫ�������ǡ���ݷ�¥������ʳ����ˮ�Ĺ�Ӧ��\n");
                        tell_object(me, "��Ȼ��Щ������Ҫ�㻨Ǯȥ��ġ�\n");
                        tell_object(me, "\n�ڷ�����������ã�����𣩲쿴���߰�����������Ƿ�������ң�����ȥ\n");
                        tell_object(me, "��������ƪ������𡡣������壮����������\n");
                        tell_object(me, "���������Ҳ�ɲο�������𣺣��������������������������\n");
                        tell_object(me, "ϣ������һ�������ķ���֮�á���\n");
                        good_luck(me);
                }
        } else {
                if(me->query("marks/newbie_intro") == 1){
                        tell_object(me, "С�������ͷ������λ"+ RANK_D->query_respect(me) +"���ж�������ף����ˣ���\n");
                        tell_object(me, "��Ӱ��һ˲����ʧ��\n");
                        me->delete("marks/newbie_intro");
                } else {
                        good_luck(me);
                }
        }
        return 1;
} 
int good_luck(object me){
        object food, drink;
        if(me->query("marks/newbie_given_food")) {
                return 0;
        }
        tell_object(me, "С����ЦЦ˵�����ܺã��������ܿ���Ӧ����ġ���\n");
        tell_object(me, "С�������в�֪��ʱ���˸����̵ĺ�«����һ������ĺ�ɫ���ӡ�\n"); 
        tell_object(me, "С�����Ѷ����ݸ���˵������������һЩʳ�����ˮ��ϣ�������£�\n");
   tell_object(me, "ף����ˣ���˲���Ӱ��ʧ��\n");
        food = new("/obj/specials/food/redfruit");
        drink = new("/obj/specials/food/calabash");
        food->move(me);
        drink->move(me);        
        me->set("marks/newbie_given_food", 1);
        me->delete("marks/newbie_intro");
}