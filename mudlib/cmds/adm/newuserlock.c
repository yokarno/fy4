 // wizlock.c
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        int lvl=0; 
        if( me!=this_player(1) ) return 0;
        if( wiz_level(me) < wiz_level("(arch)") )
                return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
        if( !arg || arg=="" )
                return notify_fail("指令格式：newuserlock <1|0>\n"); 
        if( sscanf(arg, "%d", lvl)!=1 ) lvl = atoi(arg);
        seteuid(getuid());
        if( LOGIN_D->set_newuser_lock(lvl) ) {
                write(sprintf("\n禁止新人进入游戏\n"));
                                
        } else
                write(sprintf("\n允许新人进入游戏\n"));
                return 1;
} 
int help (object me)
{
        write(@HELP
指令格式: newuserlock <1|0>
 
限制新的使用者进入游戏。 
 
HELP
);
        return 1;
}
   
