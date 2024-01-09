# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: C:\Users\pc\Desktop\VitisWs\ZyboFreeRTOS\Zybo_FreeRTOS_system\_ide\scripts\debugger_zybo_freertos-default.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source C:\Users\pc\Desktop\VitisWs\ZyboFreeRTOS\Zybo_FreeRTOS_system\_ide\scripts\debugger_zybo_freertos-default.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -nocase -filter {name =~"APU*"}
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Digilent Zybo Z7 210351B7A960A" && level==0 && jtag_device_ctx=="jsn-Zybo Z7-210351B7A960A-13722093-0"}
fpga -file C:/Users/pc/Desktop/VitisWs/ZyboFreeRTOS/Zybo_FreeRTOS/_ide/bitstream/Zybo_BD_wrapper.bit
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw C:/Users/pc/Desktop/VitisWs/ZyboFreeRTOS/Zybo_BD_wrapper/export/Zybo_BD_wrapper/hw/Zybo_BD_wrapper.xsa -mem-ranges [list {0x40000000 0xbfffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
source C:/Users/pc/Desktop/VitisWs/ZyboFreeRTOS/Zybo_FreeRTOS/_ide/psinit/ps7_init.tcl
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "*A9*#0"}
dow C:/Users/pc/Desktop/VitisWs/ZyboFreeRTOS/Zybo_FreeRTOS/Debug/Zybo_FreeRTOS.elf
configparams force-mem-access 0
bpadd -addr &main
