//tatosens.h 

/*
 * programing by dnclive(c)2011
 *  dnclive@gmail.com
*/
#ifndef tatosensh
#define tatosensh

#include <stdlib.h>
#include <stdio.h>

#include <tdeb.h>

typedef struct _tatosens tatosens ;

//данные
struct _tatosens
{
	tatosens *self;			//ссылка на себя
};


//функции
/*
	tatosens *tatosens_finit()
	функция:
		уровня 0 (для внешних вызовов) выделяющая последовательный блок памяти размера size байт
		Пример:
			
	параметры:
		int size	размер в байтах необходимый к выделению
		
	эффект:
		используется для запроса требуемого объема памяти
		
	возврат:
		возвращается указатель на участок памяти запрошенного разммера
*/
tatosens *tatosens_finit();		//инициализация библиотеки

/*
	tatosens *tatosens_fcre()
	функция:
		выделение памяти под данные библиотеки
		Пример:
			
	параметры:
		
		
	эффект:
		используется для запроса требуемого объема памяти
		
	возврат:
		возвращается указатель на участок памяти запрошенного разммера
*/
tatosens *tatosens_fcre();		//выделение памяти под данные библиотеки


#endif
