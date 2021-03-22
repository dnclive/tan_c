#makefile for tatosens

lib_dir=/usr/lib/

include_dir=/usr/include/

all: tatosens_deb
	-@echo модуль libtatosens.so собран
	
tatosens_deb: tatosens_deb.o libtatosens.so
	gcc -o tatosens_deb tatosens_deb.o -lm -L. -ltatosens -ltdeb -Wl,-rpath,.

tatosens_deb.o: tatosens_deb.c
	gcc -c tatosens_deb.c

#tatosens lib
tatosens.o: tatosens.c
	gcc -c tatosens.c

libtatosens.so: tatosens.o
	gcc -shared -o libtatosens.so tatosens.o

#установка
install: libtatosens.so tatosens.h
	#-mkdir $(lib_dir)
	#-mkdir $(include_dir)
	cp libtatosens.so $(lib_dir)
	#cp libtatosens.so /usr/lib/
	cp tatosens.h $(include_dir)
	#cp tatosens.h /usr/include/
	
	
#удаление
unintall:
	rm $(lib_dir)/libtatosens.so
	rm $(include_dir)/tatosens.h


clean:
	rm -f *.o *.a *.so
