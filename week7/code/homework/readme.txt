利用菜单切换功能
使用标准io库实现以下功能：
	创建文件
	写文件
	读文件
	修改权限
	查看权限等功能

basefunc.c实现菜单，暂停等待确认
filebase.c实现创建、写入、读取文件
premission.c实现修改文件权限、查看修改权限

baseoperate.a是用basefunc.c生成的静态库文件
fileoperate.so是用filebase.c和premission.c生成的动态库文件

test.c为本地测试文件
test是test.c用静态库和动态库编译生成的可执行文件
