 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
int give_hint();
string sysmsg;
void create()
{
        set_name(HIY"天孙"NOR, ({ "tiansun", "tian sun",  }) ); 
        set("gender", "男性");
        set("age", 80);
        set("long",
 "\n天孙是当今江湖中最神秘的组织〖天宗〗的头领，他掌握着很多人的命运。\n");
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 10);
//      set("str", 40);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
//                "连城璧向你拱了拱手道：＂这位英雄，今朝相遇，我连某深感荣幸！＂\n",
        }) );
        set("inquiry", ([
                "天宗" : (: give_hint:),
                "tianzong" : (: give_hint:) 
        ]));
        set("force", 4000);
        set("max_force", 80000);
        set("force_factor", 40);
        set("atman",1000);
        set("max_atman",1000);
        set("fly_target",1);
        set("combat_exp", 10000000);
        set_skill("unarmed", 180);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_temp("apply/attack",100);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
        set_temp("apply/damage",100); 
        set("title", HIG"天宗"NOR+WHT"首领"NOR);
//        set("nickname", HIR"侠义无双"NOR);
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        create_organization("天宗",1,"邪");
}
int accept_fight(object me)
{
        command("say 哼！我没有这等闲功夫");
        return 0;
}
void init()
{
      add_action("give_mission", "mission");
      add_action("filish_mission","filish");
//      add_action("join_in","join");
}
int filish_mission()
{
        int  exp, pot, score;
        object me;
        string mission;
        
/*        if((string)who->query("organization/org_name") != "天宗")
                return 0;*/
        me=this_player();
        
        if(!me->query("mission/over"))
        {
          tell_object(me,"天孙摇头道：你的任务还没有完成。");
          return 0;
        }
        else
        {
        tell_object(me,"天孙说道：好！做得好！天宗就需要你这样的人才！\n");
        exp = random(150) + 10;
// put a cap
        exp = exp * (int) me->query_temp("mission_number")/3;
        exp += 1;
        pot = exp / 5 + 1;
        score = 1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",-score);
        tell_object(me,HIW"你被〔天孙〕奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"NOR);
//      chinese_number(score)+"点综合评价\n"NOR);
        me->set("mission/name", 0 );
        me->set("mission/over",0);
        me->add("QUEST",1);
                        return 1;
        }
                return 1;
}
int give_mission(string arg)
{
        string mission ;
        object me;
        int j, combatexp, timep, lvl=0;
        mixed *local;
        string *npcs,*objs,file;
        int  t;
        me = this_player();
// Let's see if this player is one of us
        if((string)me->query("guild") != "天宗")
                return 0;
   if((int)me->query("last_good_kill") < ((int)me->query("mud_age") - 24*3600))
        {
                tell_object(me,"连城璧对你阴笑着说：
＂我看你对〔天宗〕并不很忠心，除非你去杀一个和你武功相当的「人」物＂\n");
                return 1;
        } 
// Let's see if this player is a ghost
        if((int) me->is_ghost())
        {
                write("鬼魂不可要任务．\n");
                return 1;
        }
        if( me->query("mission/name") && !me->query("mission/over") )
        {
        	write("你现在的任务是关于"+me->query("mission/name")+"。\n");
        return 1;
        }
// Let's see if this player still carries an un-expired task
        if((mission =  me->query("mission/name")))
        {
        if( ((int) me->query("mission_time")) >  time() )
                return 0;
        else
                me->set("kee", me->query("kee")/2+1);
                me->delete_temp("mission_number");
        }
        file = read_file("/quest/NPC");
        npcs = explode(file,"\n");
        file = read_file("/quest/OBJ");
        objs = explode(file,"\n");
        timep = random(300)+60;   //  big random factor
// A factor here to make time random
        timep = random(timep/2)+timep/2;
        time_period(timep, me);
//        if(random(2))
//        {
        mission = npcs[random(sizeof(npcs))];
        tell_object(me,"替天宗杀了"+mission+"。\n"NOR);
        sysmsg +="杀了"+mission+"。";
/*        }
        else
        {
        mission = objs[random(sizeof(objs))];
        tell_object(me,"去抢"+mission+"给天宗。\n"NOR);
        sysmsg +="去抢"+mission+"。";
   }*/
        me->set("mission/name", mission);
        me->add("vendetta/authority",1);
        me->set("mission_time", (int) time()+(int) timep);
        if((int)me->query_temp("mission_number") < 5)
        me->add_temp("mission_number",1);
        CHANNEL_D->do_sys_channel("qst", sprintf("%s(%s)：%s",
        me->query("name"),me->query("id"),sysmsg)); 
return 1;
} 
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t; 
        if(d) time = chinese_number(d) + "天";
        else time = ""; 
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒"; 
        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n在" + time + "内");
        sysmsg = "在" + time + "内";
        return 1;
}
int give_hint()
{
        object me,obj;
        me = this_player();
        obj = this_object();
        if(me->query_temp("num_of_ask") < random(4)+5)
        {
                me->add_temp("num_of_ask",1);
        tell_object(me,"连城璧道：＂〔天宗〕是当今武林中最神秘，邪恶的帮会，它笼络天下各
派高手，以暗杀方式来铲除异己。〔天宗〕的主人－－天孙的身份也是个天大的迷。
〔天宗〕经常无故残杀天下老少英雄，以巩固自己在武林中的地位！\n");
                return 1;
   }
        else{
        tell_object(me,"连城璧道：＂你似乎对〔天宗〕很感兴趣，是否想加入呢（join yes/no）？＂\n");
        return 1;
        } 
}
int join_in(string arg)
{
        object me;
        me = this_player();
        if((int)me->query_temp("num_of_ask") < 5) return 0;
        if(!arg || arg != "yes" || me->query("combat_exp") < 800000)
        {
        me->delete_temp("num_of_ask");
        me->set_temp("in_doubt",1);
        return notify_fail("连城璧道：＂〔天宗〕极邪，极毒，如果你加入〔天宗〕，
我决不放过你！＂\n");
        }
        tell_object(me,"连城璧在你耳边悄声道：
＂其实我就是〔天宗〕的少主，从今以后，你就为〔天宗〕出力吧！我绝对不会亏待你的！
你可以向我要任务（quest），但你一定要证明你是强者！＂\n");
        me->set("guild","天宗");
        me->delete_temp("num_of_ask"); 
        return 1; 
}   
