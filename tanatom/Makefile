#makefile for tanatom

lib_dir=/usr/lib/

include_dir=/usr/include/

all: tanatom_deb
	-@echo модуль libtanatom.so собран
	
tanatom_deb: tanatom_deb.o libtanatom.so
	gcc -o tanatom_deb tanatom_deb.o -lm -L. -ltanatom -ltkvl -ltdeb -ltcontext -ltcre -ltmem -ltstr -ltlist -ltlisti -ltlist_each -ltinctor -ltbit -ltstr_each -Wl,-rpath,.

tanatom_deb.o: tanatom_deb.c
	gcc -c tanatom_deb.c

#tanatom lib
tanatom.o: tanatom.c tanatom.h
	gcc -c tanatom.c

libtanatom.so: tanatom.o
	gcc -shared -o libtanatom.so tanatom.o

#установка
install: libtanatom.so tanatom.h
	#-mkdir $(lib_dir)
	#-mkdir $(include_dir)
	cp libtanatom.so $(lib_dir)
	#cp libtanatom.so /usr/lib/
	cp tanatom.h $(include_dir)
	#cp tanatom.h /usr/include/
	
	
#удаление
unintall:
	rm $(lib_dir)/libtanatom.so
	rm $(include_dir)/tanatom.h


clean:
	rm -f *.o *.a *.so
