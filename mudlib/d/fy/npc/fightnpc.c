#include <ansi.h>
inherit NPC;
void auto_smart_fight();
void ask_help();
void auto_npc_setup(string name, int basic, int special, int self_weapon, string weapon_dir, string char_type, string my_char); 
void create()
{
        set_name(HIY"秋风刀"NOR,({"guardian"}));
        set("title",YEL"恶人窟守卫"NOR);
        set("long", "这是一位恶人窟专门担任巡护之责的弟子。\n");
        set("age",30+random(20)); 
        set("combat_exp", 5500000);
        set("dungeon_npc","test");
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",60);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,180,1,"/obj/weapon/","all","all");
        setup();
        
   carry_object("/obj/armor/cloth")->wear();
}  
void auto_npc_setup(string name, int basic, int special, int auto_weapon, string weapon_dir, string char_type, string my_char) {
        
//      name ---  char name, used in random NPC generator so they have same name.
//      basic --- basic skill level (move,spells,magic,...)     
//      special --- special skill level (diesword,shenji-blade,anxiang-steps,...)
//      auto-weapon --- 0: Do not define weapon; 1: auto define a weapon using sword, blade ....
//      weapon_dir ---- when auto define weapon, the directory of weapon obj located, for exampe, "/d/fy/"
//      char_type ---- fighter_weapon,fighter_unarmed,healer,ironman,magician,zombie-wiper,
//              if you call smart_fight() in chat_chance, NPC will react according to this setting.
//              healer: heal friend in fight, ironman: have iron-cloth
//              magician: using sanqing skills.
//              char_num:
//      my_char ---- this lets you define exactly the type of NPC you want, check string *type for the correct name. 
        string *basic_skill= ({"move","dodge","parry","unarmed","blade","sword",
        "staff","axe","spells","magic","spear","throwing","hammer","whip","force",
        "perception"}); 
        string *type_fighter_w= ({
        "shenji", "bat-blade", "lefthand", "diesword","shortsong",
        "dagou-stick","yue-spear","taiji-sword","sharen-sword","longfenghuan",
        "cloudstaff","doomsword","tanzhi-shentong","qingfeng-sword","liuquan-steps",
        "qiusheng-blade","xuezhan-spear","xuanyuan-axe1","xuanyuan-axe2","softsword",
        "ittouryu","ass-hammer","pangu-hammer","thunderwhip","xinyue-dagger",           
        });
        string *type_fighter_u = ({"dragonstrike","doomstrike","taiji","hanshan-strike",
                "yiyangzhi","enmeiryu","tenderzhi","wolf-strike","bazhentu","wolf-claw",
                "nine-moon-claw","lingxi-zhi","yue-strike",
                });
        string *type_healer =({});
        string *type_magician = ({});
        string *type_ironman= ({"jin-gang","sl-hammer","sl-axe","sl-spear","sl-staff",
                        "sl-yijinjing",});
        
        int i, total;
        
        string random_choose;
        int size_w,size_u,size_i; 
        size_w=sizeof(type_fighter_w);
   size_u=sizeof(type_fighter_u);
        size_i=sizeof(type_ironman); 
        for (i=1;i<sizeof(basic_skill);i++){
                set_skill(basic_skill[i],basic);
                }
        
        set_skill("anxiang-steps", special);
        map_skill("move","anxiang-steps");
        
        if (my_char == "all")
                switch (char_type) {
                        case "fighter_w": random_choose= type_fighter_w[random(size_w)];
                                                break;
                        case "fighter_u": random_choose= type_fighter_u[random(size_u)];                
                                                break;
                        case "ironman":  random_choose= type_ironman[random(size_i)];
                                                break;
                        case "all":     total=size_w+size_u+size_i;
                                        if (random(total)>size_u+size_i) {
                                                random_choose= type_fighter_w[random(size_w)];
                                                char_type="fighter_w";
                                                }
                                                else if (random(total)>size_u)  {
                                                        random_choose=type_ironman[random(size_i)];
                                                        char_type="ironman";
                                                        }
                                                else {
                                                        random_choose= type_fighter_u[random(size_u)];
                                                        char_type="fighter_u";
                                                        }                                       
                        default:        break;
                        }                       
        
        
        if (my_char != "all")  random_choose= my_char;
                
        
        if (!random(5)) set("zombie-killer",1);
        
   if (!random(10)||char_type=="healer") {
                set("npc_type","healer");
                set("class","bonze");
                set_name("妙手回春",({name}));
                set_skill("cloudstaff",special);
                set_skill("essencemagic",200);
                set_skill("notracesnow",special+20);
                set_skill("dabei-strike",special+20);
                set_skill("lotusforce",200);
                map_skill("magic","essencemagic");
                map_skill("force","lotusforce");
                map_skill("unarmed","dabei-strike");
                map_skill("staff","cloudstaff");
                map_skill("parry","cloudstaff");
                map_skill("dodge","notracesnow");
                set("perform_attack","staff.longxianyuye");
                set("perform_attack_2","unarmed.qianshouqianbian");     
                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                return;
        }
        
        if (char_type=="magician") {
                set("npc_type","magician");
                set("class","taoist");
                set_name("辣手仙姑",({name}));
                set_skill("necromancy",special);
                set_skill("notracesnow",special+20);
                set_skill("tenderzhi",special+20);
                set_skill("gouyee",200);
                map_skill("spells","necromancy");
                map_skill("force","gouyee");
                map_skill("unarmed","tenderzhi");
                map_skill("dodge","notracesnow");
                return;
        }
        
if (char_type=="fighter_w") {           
        switch (random_choose) {         
// below are fighter_w types.
           case "shenji":   
                                set("npc_type","fighter_w");
                                set_name("神算子",({name}));
                                set_skill("shenji-blade",special);
                                set_skill("shenji-steps",special);
                                set_skill("luoriquan",special+30);
                                map_skill("unarmed","luoriquan");
                                map_skill("blade","shenji-blade");
                                map_skill("parry","shenji-blade");
                                map_skill("dodge","shenji-steps");
                                set("perform_attack","blade.jichulianhuan");
                                set("perform_attack_2","unarmed.luori");
                                set("perform_busy","dodge.shenjimiaosuan");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "bat-blade": 
                                set("npc_type","fighter_w");
                                set("class","bat");
                                set_name("飞天蝙蝠",({name}));
                                set_skill("bat-blade",special-20);
                                set_skill("meng-steps",special);
                                set_skill("luoriquan",special+30);
                                map_skill("unarmed","luoriquan");
                                map_skill("blade","bat-blade");
                                map_skill("parry","bat-blade");
                                map_skill("dodge","meng-steps");
                                set("perform_attack","blade.shiwanshenmo");
                                set("perform_attack_2","unarmed.luori");
                                set("perform_busy","dodge.huanyinqianchong");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "lefthand": 
                                set("npc_type","fighter_w");
                                set("class","assassin");
                                set_name("毒剑",({name}));
                                set_skill("lefthand-sword",special+20);
                                set_skill("jinhong-steps",special+20);
                                set_skill("flame-strike",special+20);
                                map_skill("unarmed","flame-strike");
                           map_skill("sword","lefthand-sword");
                                map_skill("parry","lefthand-sword");
                                map_skill("dodge","jinhong-steps");
                                set("perform_attack","sword.duxin");
                                set("perform_busy","dodge.canglongzhaxian");    
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "diesword": 
                                set("npc_type","fighter_w");
                                set_name("花蝴蝶",({name}));
                                set("class","legend");
                                set("gender","女性");
                                set_skill("diesword",special-20);
                                set_skill("fall-steps",special+50);
                                set_skill("qidaoforce",special);
                                map_skill("unarmed","qidaoforce");
                                map_skill("sword","diesword");
                                map_skill("parry","diesword");
                                map_skill("dodge","fall-steps");
                                set("perform_attack","sword.caidiekuangwu");
                                set("perform_busy","dodge.luoyeqiufeng");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "shortsong": 
                                set("npc_type","fighter_w");
                                set_name("秋风",({name}));
                                set("class","legend");
                                set_skill("shortsong-blade",special-10);
                                set_skill("fall-steps",special+50);
                                set_skill("qidaoforce",special+50);
                                map_skill("unarmed","qidaoforce");
                                map_skill("blade","shortsong-blade");
                                map_skill("parry","shortsong-blade");
                                map_skill("dodge","fall-steps");
                                set("perform_attack","blade.duangechangmeng");
                                set("perform_busy","dodge.luoyeqiufeng");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "dagou-stick": 
                           set_name("天下无狗",({name}));
                                set("class","beggar");
                                set_skill("dragonstrike",special+20);
                                set_skill("doggiesteps",special+80);
                                set_skill("dagou-stick",special);
                                map_skill("staff","dagou-stick");
                                map_skill("parry","dagou-stick");
                                map_skill("unarmed","dragonstrike");
                                map_skill("dodge","doggiesteps");
                                set("perform_attack","staff.tianxiawugou");
                                set("perform_attack_2","unarmed.xianglongwuhui");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                                break;
                case "yue-spear": 
                                set_name("铁枪",({name}));
                                set("class","official");
                                set_skill("changquan",260);
                                set_skill("puti-steps",special+80);
                                set_skill("yue-spear",special);
                                set_skill("manjianghong",special);
                                map_skill("force","manjianghong");
                                map_skill("spear","yue-spear");
                                map_skill("parry","yue-spear");
                                map_skill("unarmed","changquan");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","spear.zonghengtianxia");
                                set("perform_attack_2","unarmed.yuhuan");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();
                                break;
                case "taiji-sword": 
                                set_name("棉里藏针",({name}));
                                set("class","wudang");
                                set_skill("taiji",special);
                                set_skill("five-steps",special);
                                set_skill("taiji-sword",special+50);
                                set_skill("taijiforce",200);
                                map_skill("force","taijiforce");
                                map_skill("sword","taiji-sword");
                                map_skill("unarmed","taiji");
                           map_skill("dodge","five-steps");
                                set("perform_attack","sword.chanzijue");
                                set("perform_attack_2","nianzijue");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "sharen-sword": 
                                set("class","assassin");
                                set_name("杀人如麻",({name}));
                                set_skill("lefthand-sword",special+20);
                                set_skill("sharen-sword",special+20);
                                set_skill("jinhong-steps",special+20);
                                set_skill("flame-strike",special+20);
                                map_skill("unarmed","flame-strike");
                                map_skill("sword","sharen-sword");
                                map_skill("parry","lefthand-sword");
                                map_skill("dodge","jinhong-steps");
                                set("perform_attack","sword.sharenruma");
                                set("perform_busy","dodge.canglongzhaxian");    
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "longfenghuan": 
                                set("class","assassin");
                                set_name("双飞燕",({name}));
                                set_skill("longfenghuan",special);
                                set_skill("jinhong-steps",special+20);
                                set_skill("flame-strike",special+20);
                                map_skill("unarmed","flame-strike");
                                map_skill("hammer","longfenghuan");
                                map_skill("parry","longfenghuan");
                                map_skill("dodge","jinhong-steps");
                                set("perform_attack","hammer.longfengshuangfei");
                                set("perform_busy","dodge.canglongzhaxian");    
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();
                                break;
                case "cloudstaff": 
                                set("class","bonze");
                                set_name("浮云写意",({name}));
                                set_skill("cloudstaff",special);
                                set_skill("notracesnow",special+20);
                           set_skill("dabei-strike",special+20);
                                map_skill("unarmed","dabei-strike");
                                map_skill("staff","cloudstaff");
                                map_skill("parry","cloudstaff");
                                map_skill("dodge","notracesnow");
                                set("perform_attack","staff.longxianyuye");
                                set("perform_attack_2","unarmed.qianshouqianbian");     
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();
                                break;
                case "doomsword": 
                                set("class","fighter");
                                set_name("湘西一剑",({name}));
                                set_skill("doomsword",special);
                                set_skill("doomstrike",special);
                                set_skill("doomsteps",special);
                                map_skill("unarmed","doomstrike");
                                map_skill("sword","doomsword");
                                map_skill("parry","doomsword");
                                map_skill("dodge","doomsteps");
                                set("perform_attack","sword.hunranyijian");
                                set("perform_attack_2","unarmed.hantian");      
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "xuezhan-spear":   
                                set_name("血枪",({name}));
                                set("class","fugui");
                                set_skill("xuezhan-spear",special);
                                set_skill("hawk-steps",special);
                                set_skill("eagle-claw",special+30);
                                set_skill("skyforce",200);
                                map_skill("force","skyforce");
                                map_skill("unarmed","eagle-claw");
                                map_skill("spear","xuezhan-spear");
                                map_skill("parry","xuezhan-spear");
                                map_skill("dodge","hawk-steps");
                                set("perform_attack","spear.bafangfengyu");
                                set("perform_busy","dodge.yingjichangkong");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();
                                break;

                case "liuquan-steps":   
                                set_name("流泉",({name}));
                                set("class","huangshan");
                                set("gender","女性");
                                set_skill("siqi-sword",special);
                                set_skill("liuquan-steps",special);
                                set_skill("yunwu-strike",special);
                                set_skill("xianjing",200);
                                map_skill("force","xianjing");
                                map_skill("unarmed","yunwu-strike");
                                map_skill("sword","siqi-sword");
                                map_skill("parry","siqi-sword");
                                map_skill("dodge","liuquan-steps");
                                set("perform_busy","dodge.liushuichanchan");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "qiusheng-blade":  
                                set_name("秋声",({name}));
                                set("class","huangshan");
                                set("gender","男性");
                                set_skill("qiusheng-blade",special);
                                set_skill("liuquan-steps",special);
                                set_skill("yunwu-strike",special);
                                set_skill("xianjing",200);
                                map_skill("force","xianjing");
                                map_skill("unarmed","yunwu-strike");
                                map_skill("sword","qiusheng-blade");
                                map_skill("parry","qiusheng-blade");
                                map_skill("dodge","liuquan-steps");
                                set("perform_busy","dodge.liushuichanchan");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();
                                break;
                case "qingfeng-sword":  
                                set_name("清风",({name}));
                                set("class","huashan");
                                set("gender","男性");
                                set_skill("qingfeng-sword",special+20);
                                set_skill("anxiang-steps",special);
                                set_skill("zhaixin-claw",special);
                           set_skill("hanmei-force",200);
                                map_skill("force","hanmei-force");
                                map_skill("unarmed","zhaixin-claw");
                                map_skill("sword","qingfeng-sword");
                                map_skill("parry","qingfeng-sword");
                                map_skill("dodge","anxiang-steps");
                                set("perform_busy","dodge.yexuechuji");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();
                                break;
                case "tanzhi-shentong": 
                                set_name("千手观音",({name}));
                                set("class","huashan");
                                set("gender","女性");
                                set_skill("tanzhi-shentong",special);
                                set_skill("anxiang-steps",special);
                                set_skill("zhaixin-claw",special);
                                set_skill("hanmei-force",200);
                                map_skill("force","hanmei-force");
                                map_skill("unarmed","zhaixin-claw");
                                map_skill("throwing","tanzhi-shentong");
                                map_skill("dodge","anxiang-steps");
                                set("perform_attack","throwing.mantianhuayu");
                                set("perform_busy","throwing.tanzhijinghun");
                                if (auto_weapon) carry_object(weapon_dir+"dart")->wield();
                                break;  
                case "xuanyuan-axe1": 
                                set("npc_type","fighter_w");
                                set("class","knight");
                                set_name("霹雳斧",({name}));
                                set_skill("hanshan-strike",special);
                                set_skill("windy-steps",special);
                                set_skill("xuanyuan-axe",special);
                                map_skill("parry","xuanyuan-axe");
                                map_skill("axe","xuanyuan-axe");
                                map_skill("unarmed","hanshan-strike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack","axe.guifushengong");
                                set("perform_attack_2","unarmed.zhangjian");
                                set("perform_busy","dodge.fengliu");
                           if (auto_weapon) carry_object(weapon_dir+"axe")->wield();        
                                break;
                case "xuanyuan-axe2": 
                                set("npc_type","fighter_w");
                                set("class","knight");
                                set_name("雷霆斧",({name}));
                                set_skill("hanshan-strike",special);
                                set_skill("windy-steps",special);
                                set_skill("xuanyuan-axe",special);
                                map_skill("parry","axe.xuanyuan-axe");
                                map_skill("axe","xuanyuan-axe");
                                map_skill("unarmed","hanshan-strike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack","axe.jiuqipoxiao");
                                set("perform_attack_2","unarmed.zhangjian");
                                set("perform_busy","dodge.fengliu");
                                if (auto_weapon) carry_object(weapon_dir+"axe")->wield();       
                                break;
                case "softsword": 
                                set("npc_type","fighter_w");
                                set("class","swordsman");
                                set_name("剑奴",({name}));
                                set_skill("yue-strike",special);
                                set_skill("shadowsteps",special+50);
                                set_skill("softsword",special);
                                map_skill("sword","softsword");
                                map_skill("parry","softsword");
                                map_skill("unarmed","yue-strike");
                                map_skill("dodge","shadowsteps");
                                set("perform_attack","sword.muyufeihong");
                                set("perform_attack_2","dodge.lianhuanjiao");
                                if (auto_weapon) carry_object(weapon_dir+"sword")->wield();     
                                break;                          
                case "ittouryu": 
                                set("npc_type","fighter_w");
                                set("class","ninja");
                                set_name("恶鬼",({name}));
                                set_skill("yue-strike",special);
                                set_skill("ghosty-steps",special);
                           set_skill("ittouryu",special);
                                map_skill("blade","ittouryu");
                                map_skill("unarmed","yue-strike");
                                map_skill("dodge","ghosty-steps");
                                set("perform_attack","blade.hyakki");
                                if (auto_weapon) carry_object(weapon_dir+"blade")->wield();     
                                break;
                case "ass-hammer": 
                                set("npc_type","fighter_w");
                                set("class","wolf");
                                set_name("搏浪",({name}));
                                set_skill("wolf-strike",special);
                                set_skill("xueyeqianzong",special);
                                set_skill("assasin-hammer",special);
                                map_skill("hammer","assasin-hammer");
                                map_skill("parry","assasin-hammer");
                                map_skill("unarmed","wolf-strike");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack_2","unarmed.duanhou");
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();    
                                break;                          
                case "pangu-hammer": 
                                set("npc_type","fighter_w");
                                set("class","yinshi");
                                set_name("轰天锤",({name}));
                                set_skill("pofeng-strike",special);
                                set_skill("zuixian-steps",special+20);
                                set_skill("pangu-hammer",special);
                                map_skill("hammer","pangu-hammer");
                                map_skill("parry","pangu-hammer");
                                map_skill("unarmed","pofeng-strike");
                                map_skill("dodge","zuixian-steps");
                                set("perform_attack","hammer.kaitianpidi");
                                set("perform_attack_2","unarmed.luanpofeng");
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();    
                                break;  
                default:        
                case "thunderwhip": 
                                set("npc_type","fighter_w");
                           set("class","yinshi");
                                set_name("飞龙",({name}));
                                set_skill("pofeng-strike",special);
                                set_skill("zuixian-steps",special+20);
                                set_skill("pangu-hammer",200);
                                set_skill("thunderwhip",special);
                                map_skill("hammer","pangu-hammer");
                                map_skill("whip","thunderwhip");
                                map_skill("parry","thunderwhip");
                                map_skill("unarmed","pofeng-strike");
                                map_skill("dodge","zuixian-steps");
                                set("marks/hammerwhip",1); 
                                set("perform_attack","whip.tianleiyiji");
                                set("perform_attack_2","unarmed.luanpofeng");
                                if (auto_weapon) carry_object(weapon_dir+"whip")->wield();      
                                break;  
                case "xinyue-dagger": 
                                set("npc_type","fighter_w");
                                set("class","wolfmount");
                                set_name("乾坤",({name}));
                                set_skill("wolf-strike",special);
                                set_skill("xueyeqianzong",special+20);
                                set_skill("xinyue-dagger",special-40);
                                set_skill("assasin-hammer",200);
                                map_skill("dagger","xinyue-dagger");
                                map_skill("parry","assasin-hammer");
                                map_skill("unarmed","wolf-strike");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack","dagger.douzhuanxingyi");
                                set("perform_attack_2","unarmed.duanhou");
                                if (auto_weapon) carry_object(weapon_dir+"dagger")->wield();    
                                break;  
                } 
        } else  {
// below are fighter_u types:                                   
                switch (random_choose) {
                case "dragonstrike": 
                                set("npc_type","fighter_u");
                                set_name("降龙",({name}));
                           set("class","beggar");
                                set_skill("dragonstrike",special+20);
                                set_skill("doggiesteps",special+80);
                                set_skill("dagou-stick",special);
                                map_skill("staff","dagou-stick");
                                map_skill("parry","dagou-stick");
                                map_skill("unarmed","dragonstrike");
                                map_skill("dodge","doggiesteps");
                                set("perform_attack_2","unarmed.xianglongwuhui");
                                break;
                case "taiji": 
                                set_name("如意",({name}));
                                set("class","wudang");
                                set_skill("taiji",special);
                                set_skill("five-steps",special);
                                set_skill("taijiforce",200);
                                map_skill("force","taijiforce");
                                map_skill("unarmed","taiji");
                                map_skill("dodge","five-steps");
                                set("perform_attack_2","unarmed.nianzijue");
                                break;
                case "bazhentu": 
                                set_name("失魂夺魄",({name}));
                                set("class","wudang");
                                set_skill("taiji",special);
                                set_skill("five-steps",special);
                                set_skill("taijiforce",200);
                                map_skill("force","taijiforce");
                                map_skill("unarmed","taiji");
                                map_skill("dodge","five-steps");
                                set("perform_attack_2","dodge.bazhentu");
                                break;
                case "doomstrike": 
                                set("npc_type","fighter_u");
                                set("class","fighter");
                                set_name("单掌断魂",({name}));
                                set_skill("doomstrike",special);
                                set_skill("doomsteps",special);
                                map_skill("unarmed","doomstrike");
                           map_skill("dodge","doomsteps");
                                set("perform_attack_2","unarmed.hantian");      
                                break;
                case "hanshan-strike": 
                                set("npc_type","fighter_u");
                                set("class","knight");
                                set_name("姑苏",({name}));
                                set_skill("hanshan-strike",special);
                                set_skill("windy-steps",special);
                                map_skill("unarmed","hanshan-strike");
                                map_skill("dodge","windy-steps");
                                set("perform_attack_2","unarmed.zhangjian");
                                set("perform_busy","dodge.fengliu");    
                                break;
                case "yiyangzhi": 
                                set("npc_type","fighter_u");
                                set("class","shaolin");
                                set_name("一阳",({name}));
                                set_skill("yiyangzhi",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","yiyangzhi");
                                map_skill("dodge","puti-steps");
                                set("perform_attack_2","unarmed.qiankun");
                                break;
                case "enmeiryu": 
                                set("npc_type","fighter_u");
                                set("class","ninja");
                                set_name("紫电",({name}));
                                set_skill("enmeiryu",special);
                                set_skill("ghosty-steps",special);
                                map_skill("unarmed","enmeiryu");
                                map_skill("dodge","ghosty-steps");
                                set("perform_attack_2","unarmed.shiden");
                                break;
                case "tenderzhi": 
                                set("npc_type","fighter_u");
                           set("class","taoist");
                                set_name("柔虹",({name}));
                                set("gender","女性");
                                set_skill("tenderzhi",special);
                                set_skill("iron-cloth",basic);
                                set_skill("puti-steps",special);
                                map_skill("unarmed","tenderzhi");
                                map_skill("dodge","puti-steps");
                                set("perform_attack_2","unarmed.qiankun");
                                break;
                case "wolf-strike": 
                                set("npc_type","fighter_u");
                                set("class","wolfmount");
                                set_name("穿心爪",({name}));
                                set_skill("wolf-strike",special);
                                set_skill("xueyeqianzong",special);
                                map_skill("unarmed","wolf-strike");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack_2","unarmed.duanhou");
                                break;
                case "wolf-claw": 
                                set("npc_type","fighter_u");
                                set("class","wolfmount");
                                set_name("勾心爪",({name}));
                                set_skill("wolf-claw",special);
                                set_skill("xueyeqianzong",special);
                                map_skill("unarmed","wolf-claw");
                                map_skill("dodge","xueyeqianzong");
                                set("perform_attack_2","unarmed.ningxie");
                                break;
                case "nine-moon-claw": 
                                set("npc_type","fighter_u");
                                set("class","shenshui");
                                set_name("勾心爪",({name}));
                                set_skill("nine-moon-claw",special);
                                set_skill("nine-moon-steps",special);
                                map_skill("unarmed","nine-moon-claw");
                                map_skill("dodge","nine-moon-steps");
                                set("perform_busy","dodge.lianhuanbu");
                           set("force_factor",100);
                                break;
                case "lingxi-zhi": 
                                set("npc_type","fighter_u");
                                set("class","");
                                set_name("缠丝手",({name}));
                                set_skill("lingxi-zhi",special);
                                set_skill("iron-cloth",special);
                                set_skill("yijinjing",special-50);
                                map_skill("unarmed","lingxi-zhi");
                                map_skill("iron-cloth","yijinjing");
                                set("force_factor",100);
                                set("no_busy",10);
                                break;
                case "yue-strike": 
                                set("npc_type","fighter_u");
                                set("class","");
                                set_name("百花拳",({name}));
                                set_skill("yue-strike",special);
                                set_skill("iron-cloth",special);
                                set_skill("yijinjing",special-50);
                                map_skill("unarmed","yue-strike");
                                map_skill("iron-cloth","yijinjing");
                                set("force_factor",100);
                                set("no_busy",10);
                                break;
// below are ironman types:
                case "jin-gang": 
                                set("npc_type","ironman");
                                set("class","lama");
                                set_name("铁汉",({name}));
                                set_skill("bloodystrike",special);
                                set_skill("cloudstaff",special);
                                set_skill("iron-cloth",basic);
                                set_skill("jin-gang",special);
                                map_skill("parry","cloudstaff");
                                map_skill("staff","cloudstaff");
                                map_skill("iron-cloth","jin-gang");
                                map_skill("unarmed","bloodystrike");
                           map_skill("dodge","windy-steps");
                                set("perform_attack","staff.longxianyuye");
                                set("perform_busy_2","unarmed.fefawubian");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();     
                                break;
                case "sl-hammer": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set_name("流星",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("liuxing-hammer",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("parry","liuxing-hammer");
                                map_skill("hammer","liuxing-hammer");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-trike");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","hammer.fanbei");
                                if (auto_weapon) carry_object(weapon_dir+"hammer")->wield();    
                                break;
                case "sl-axe": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set_name("泼风",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("wuche-axe",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("parry","wuche-axe");
                                map_skill("axe","wuche-axe");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-trike");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","axe.sanbanfu");
                                set("perform_busy_2","unarmed.fefawubian");
                                if (auto_weapon) carry_object(weapon_dir+"axe")->wield();       
                           break;
                case "sl-spear": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set_name("索魂客",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("duanhun-spear",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("parry","duanhun-spear");
                                map_skill("spear","duanhun-spear");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-trike");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","spear.suomengchanhun");
                                set("perform_busy_2","unarmed.fefawubian");
                                if (auto_weapon) carry_object(weapon_dir+"spear")->wield();     
                                break;
                case "sl-staff": 
                                set("npc_type","ironman");
                                set("class","shaolin");
                                set_name("伏魔客",({name}));
                                set_skill("dabei-strike",special);
                                set_skill("fumostaff",special);
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special/2);
                                set_skill("puti-steps",special);
                                map_skill("parry","fumotaff");
                                map_skill("staff","fumostaff");
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","dabei-strike");
                                map_skill("dodge","puti-steps");
                                set("perform_attack","staff.hequhecong");
                                if (auto_weapon) carry_object(weapon_dir+"staff")->wield();     
                                break;
                default:        
                case "sl-yijinjing": 
                                set("npc_type","ironman");
                           set("class","shaolin");
                                set("no_busy",10);
                                set_name("金刚",({name}));
                                set_skill("iron-cloth",basic);
                                set_skill("yijinjing",special);
                                set_skill("puti-steps",special);
                                map_skill("iron-cloth","yijinjing");
                                map_skill("unarmed","yijinjing");
                                map_skill("dodge","puti-steps");
                                set("force_factor",100);
                                break;
                }
}
} 
auto_smart_fight()
{
        int i,n,j,count;
        string pfm_weapon_attack,pfm_dodge_busy;
        string pfm_unarmed_attack,pfm_unarmed_busy;
        object *enemy, me, weapon;
        
        me= this_object();
        
        if (me->query("npc_type")=="healer") {
                help_friend();
        }       
                
                
        
        pfm_weapon_attack = me->query("perform_attack");
        pfm_unarmed_attack = me->query("perform_attack_2");
        pfm_dodge_busy = me->query("perform_busy");
        pfm_unarmed_busy = me->query("perform_busy_2");
        
        n=1;
//      if (pfm_unarmed_busy) n=8;
        if (pfm_dodge_busy) n =3;
        
        enemy = this_object()->query_enemy();
   ask_help(); 
        if (me->query("npc_type")=="healer")    return;
                
        if (me->query("zombie-killer")) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                }
                if (count>=3)
                        command("perform zombie-wp1");
        }
        
        
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<n*this_object()->query("combat_exp")) {
                                if (pfm_dodge_busy)
                                        this_object()->perform_action(pfm_dodge_busy);                  
                        }
                        if (enemy[i]->is_busy() || n==1 ) {
                                if (!me->query_temp("weapon")) {
                                        if (pfm_unarmed_attack)
                                        this_object()->perform_action(pfm_unarmed_attack);
                                } else if (pfm_weapon_attack)
                                        this_object()->perform_action(pfm_weapon_attack);       
                        }
                }
        }
}  
void ask_help() {
        object me, *enemy, *inv, ob;
        string type;
        int i, j;
        
        me= this_object();
        type = me->query("dungeon_npc");
        if (!type) return;
   enemy = me->query_enemy();
        inv = all_inventory(environment(this_object()));
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type || ob==me) {
                        continue;
                }
                for (j=0;j<sizeof(enemy);j++) {
                        if (ob->is_fighting(enemy[j])) {
                                continue;
                                }
                        ob->kill_ob(enemy[j]);
                }               
        }
}  
void help_friend() {
        object me, *inv, ob;
        string type;
        int i, j;
        
        me= this_object();
        type = me->query("dungeon_npc");
        inv = all_inventory(environment(this_object()));
        
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if (userp(ob) || !ob->is_character() || ob->is_corpse() 
                        || ob->query("dungeon_npc")!=type) {
                        continue;
                }
                if (ob->query("kee")>ob->query("max_kee")/3 
                        && ob->query("eff_kee")>ob->query("max_kee")/3
                        && ob->query("gin")>ob->query("max_gin")/3 
                        && ob->query("eff_gin")>ob->query("max_gin")/3
                        && ob->query("sen")>ob->query("max_sen")/3 
                        && ob->query("eff_sen")>ob->query("max_sen")/3)
                {
                        continue;
           }
                if (ob!=me)
                        message_vision(HIY "$N运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"NOR,me,ob);
                        else
                                message_vision(HIY "$N运起内功，缓缓地将真气在体内流转....\n\n"NOR,me);
                        call_out("heal_him", 6, me, ob);
                        me->start_busy(2);
                        return;
                                
        }
        return;
}  
int heal_him(object me, object target)
{
        int amount;
        amount=6000;
        if (!objectp(me)) return 0;
        if (me->is_unconcious()) return 0;
        
        if (!present(target,environment(me))) {
                tell_object(me,"你要救治的人已经不在这里了。\n");
                return notify_fail("");
                }
        if (target!=me)
        message_vision(HIY"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n"NOR,me,target);
        else 
        message_vision(HIY"过了不久，$N吐出一口瘀血，脸色看起来红润多了。\n"NOR,me);
        target->receive_curing("kee", amount);
        target->receive_curing("sen", amount/2);
        target->receive_curing("gin", amount/2);
        if (target->query("kee")+ amount<target->query("max_kee"))
                target->add("kee",amount);
                else target->set("kee",target->query("max_kee"));
        if (target->query("sen")+ amount/2<target->query("max_sen"))
                target->add("sen",amount/2);
                else target->set("sen",target->query("max_sen"));
        if (target->query("gin")+ amount/2<target->query("max_gin"))
                target->add("gin",amount/2);
                else target->set("gin",target->query("max_gin"));
   return 1;
}  
void die(){
        object *inv, ob;
        int i;
        message_vision(HIR"\n$N惨叫一声倒了下去，化作一阵轻烟消失了。\n"NOR,this_object());     
        destruct(this_object());        
}     

