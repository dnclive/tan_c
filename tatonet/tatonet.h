//tatonet.h 

/*
 * programing by dnclive(c)2011
 *  dnclive@gmail.com
*/
#ifndef tatoneth
#define tatoneth

#include <stdlib.h>
#include <stdio.h>

#include <tdeb.h>
#include <tcontext.h>
#include <tcre.h>
#include <tstr.h>
#include <tmem.h>
#include <tlist.h>
#include <tlist_each.h>
#include <tanatom.h>

typedef struct _tatonet tatonet ;

typedef tatonet * tatonetp ;

typedef tatonet ** tatonetpp ;

//данные
struct _tatonet
{
	//tatonet *self;			//ссылка на себя
	tlistp sensor;				//список сенсоров сети
	tlistp motor;				//список моторных нейронов сети
	
};


//функции

/*
	tatonet *tatonet_fcre()
	функция:
		создание нейронной сети
		Пример:
			
	параметры:
		указатель на указатель на создаваемую сеть
		
	эффект:
		используется для запроса требуемого объема памяти
		
	возврат:
		возвращается указатель на участок памяти запрошенного разммера
*/
tatonetp tatonet_fcre(tatonetpp selfp);			//выделение памяти под данные библиотеки

/*
	tatonet *tatonet_fcre()
	функция:
		создание нейронной сети
		Пример:
			
	параметры:
		указатель на указатель на создаваемую сеть
		
	эффект:
		используется для запроса требуемого объема памяти
		
	возврат:
		возвращается указатель на участок памяти запрошенного разммера
*/
tatonetp tatonet_fadd_sensor(tatonetpp selfp, tanatomp atom);		//добавление атома в список сенсоров

tatonetp tatonet_fadd_motor(tatonetpp selfp, tanatomp atom);		//добавление в список моторных

//tatonet *tatonet_fadd_(tatonetpp selfp, tanatomp atom);		//выделение памяти под данные библиотеки


#endif
