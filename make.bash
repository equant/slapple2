cc65 -g -Oi -t apple2 slackui.c
cc65 -g -Oi -t apple2 inputline.c 
cc65 -g -Oi -t apple2 menu.c 
cc65 -g -Oi -t apple2 screen.c 
ca65 -g slackui.s 
ca65 -g inputline.s 
ca65 -g menu.s 
ca65 -g screen.s 
ld65 -o slackui -t apple2 slackui.o inputline.o menu.o screen.o apple2.lib

#cl65 -t apple2 slackui.c -o slackui
#cl65 -c -Oirs -t apple2 slackui.c -o slackui
java -jar ~/bin/AppleCommander.jar -d hello.dsk slack
java -jar ~/bin/AppleCommander.jar -as hello.dsk slack bin < slackui
java -jar ~/bin/AppleCommander.jar -l hello.dsk
java -jar ~/bin/AppleCommander.jar -as ~/bin/ADTPro-2.1.0/disks/dev.dsk slack bin < slapple2.apple2 
