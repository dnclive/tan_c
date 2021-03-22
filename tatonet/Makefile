#makefile for tatonet

lib_dir=/usr/lib/

include_dir=/usr/include/

all: tatonet_deb
	-@echo модуль libtatonet.so собран
	
tatonet_deb: tatonet_deb.o libtatonet.so
	gcc -o tatonet_deb tatonet_deb.o -lm -L. -ltatonet -ltinctor -ltkvl -ltdeb -ltcontext -ltcre -ltmem -ltstr -ltlist -ltlisti -ltlist_each -Wl,-rpath,.

tatonet_deb.o: tatonet_deb.c
	gcc -c tatonet_deb.c

#tatonet lib
tatonet.o: tatonet.c tatonet.h
	gcc -c tatonet.c

libtatonet.so: tatonet.o
	gcc -shared -o libtatonet.so tatonet.o

#установка
install: libtatonet.so tatonet.h
	#-mkdir $(lib_dir)
	#-mkdir $(include_dir)
	cp libtatonet.so $(lib_dir)
	#cp libtatonet.so /usr/lib/
	cp tatonet.h $(include_dir)
	#cp tatonet.h /usr/include/
	
	
#удаление
unintall:
	rm $(lib_dir)/libtatonet.so
	rm $(include_dir)/tatonet.h


clean:
	rm -f *.o *.a *.so
