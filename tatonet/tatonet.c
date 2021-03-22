/*
 * tatonet.c
 */

#include "tatonet.h"


tatonet *tatonet_finit()								//инициализация
{

}

tatonetp tatonet_fcre(tatonetpp selfp)					//выделение памяти под данные библиотеки
{
	tdeb_fdeb3("tatonet_deb", __FILE__, __LINE__, "selfp=%p\r\n", selfp);
	
	tatonetp self=tcre_ftptr(selfp, tcre_mptr_cnt(tatonetp,1));	//выделение указателей для tatonet
	
	tlist_fcre(&self->sensor);						//список сенсоров
	tlist_fcre(&self->motor);						//список моторов
	
	tdeb_fdeb3("tinctor_deb", __FILE__, __LINE__, "self=%p\r\n", self);
	
	//возвращаем результат
	return self;
}

tatonetp tatonet_fadd_sensor(tatonetpp selfp, tanatomp atom)		//добавление атома в список сенсоров
{
	//***проверка входных данных
	if (!selfp)		//нет указателя не с чем работать
	{
		return NULL;
	}
	if (!*selfp)
	{
		return NULL;
	}
	tatonetp self=*selfp;
	if (!atom)
	{
		return self;
	}
	//***проверка входных данных
	
	tlist_fadd_data(&self->sensor, atom);		//добавляем переданный атом в список сенсоров
	
	return self;
	
}

tatonetp tatonet_fadd_motor(tatonetpp selfp, tanatomp atom)		//добавление в список моторных
{
	//***проверка входных данных
	if (!selfp)		//нет указателя не с чем работать
	{
		return NULL;
	}
	if (!*selfp)
	{
		return NULL;
	}
	tatonetp self=*selfp;
	if (!atom)
	{
		return self;
	}
	//***проверка входных данных
	
	tlist_fadd_data(&self->motor, atom);		//добавляем переданный атом в список моторов
	
	return self;
}

