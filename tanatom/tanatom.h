//tanatom.h 

/*
 * programing by dnclive(c)2011
 *  dnclive@gmail.com
*/
#ifndef tanatomh
#define tanatomh

#include <stdlib.h>
#include <stdio.h>

#include <tdeb.h>
#include <tcontext.h>
#include <tcre.h>
#include <tstr.h>
#include <tmem.h>
#include <tlist.h>
#include <tlist_each.h>
#include <tinctor.h>


typedef struct _tanatom tanatom ;

typedef struct _tanatom * tanatomp ;

typedef struct _tanatom ** tanatompp ;

//данные
struct _tanatom
{
	//tcontextp context;	//контекст
	//tanatom *self;		//ссылка на себя
	tlistp relat;			//список атомов с которыми связан текущий (передает сгнал)
	tp core;				//ядро атома - есть данные обрабатываемые сетью
	tinctorp effort;		//уровень сигнала атома
	tinctorp freq;			//частора работы атома
	tlongp touch;			//идентификатор текущего такта
};


/*
	tanatom *tanatom_fcre()
	функция:
		выделение памяти под данные библиотеки
		Пример:
			
	параметры:
		
		
	эффект:
		используется для запроса требуемого объема памяти
		
	возврат:
		возвращается указатель на участок памяти запрошенного разммера
*/
tanatomp tanatom_fcre(tanatompp selfp);		//выделение памяти под данные библиотеки

/*
	tanatom *tanatom_fcre()
	функция:
		выделение памяти под данные библиотеки
		Пример:
			
	параметры:
		
		
	эффект:
		используется для запроса требуемого объема памяти
		
	возврат:
		возвращается указатель на участок памяти запрошенного разммера
*/
//выделение памяти под данные библиотеки
tanatomp tanatom_fcre_lim_freq(tanatompp selfp, tlong effort_lim, tlong freq_lim);

/*
	tanatom *tanatom_fcre()
	функция:
		выделение памяти под данные библиотеки
		Пример:
			
	параметры:
		
		
	эффект:
		используется для запроса требуемого объема памяти
		
	возврат:
		возвращается указатель на участок памяти запрошенного разммера
*/
//выделение памяти под данные библиотеки
tanatomp tanatom_fcre_core_lim_freq(tanatompp selfp, tp core, tlong effort_lim, tlong freq_lim);

//добавление связи на атом
//те добавление ссылки на атом в свой список
tanatomp tanatom_frelat(tanatompp selfp, tanatomp atom);

/*
	tanatomp tanatom_femit(tanatompp selfp, tanatomp atom)
	функция:
		выполняет излучение атома, те передаем сигнал на атомы с которыми есть связь,
		при условии что предел своего сигнала превышен
		Пример:
			
	параметры:
		
		
	эффект:
		используется для запроса требуемого объема памяти
		
	возврат:
		возвращается указатель на участок памяти запрошенного разммера
*/
tanatomp tanatom_femit(tanatompp selfp);


/*
	tanatomp tanatom_finc(tanatompp selfp, tanatomp atom)
	функция:
		инкрементирует текущий уровень сигнала атома effort->val
		Пример:
			
	параметры:
		
		
	эффект:
		используется для запроса требуемого объема памяти
		
	возврат:
		возвращается указатель на участок памяти запрошенного разммера
*/
tanatomp tanatom_finc(tanatompp selfp);


#endif
