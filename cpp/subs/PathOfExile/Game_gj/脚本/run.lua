加载配置脚本("通用函数")
加载配置脚本("通用配置")

--返回应该运行的脚本名
定义函数 运行时决定该运行什么脚本()
    返回 "做任务升级"
    --返回 "异界"
结束


局部变量 由游戏前场景进入到游戏场景 = 场景连接器({
    通用_登陆场景,
    通用_选择角色场景
})
由游戏前场景进入到游戏场景:添加目标场景(游戏内场景(定义函数 () 结束))
自动选择运行脚本(由游戏前场景进入到游戏场景, 运行时决定该运行什么脚本)
