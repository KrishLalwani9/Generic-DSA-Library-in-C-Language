gcc -c *.c -I ..\include
ar rcs my.lib *.o
del *.o
move my.lib ..\lib