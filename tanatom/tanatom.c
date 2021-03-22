/*
 * tanatom.c
 */

#include "tanatom.h"


tanatom *tanatom_finit()								//инициализация
{

}

tanatomp tanatom_fcre(tanatompp selfp)								//выделение памяти под данные библиотеки
{
	tdeb_fdeb3("tanatom_deb", __FILE__, __LINE__, "selfp=%p\r\n", selfp);
	
	
	tanatomp self=tcre_ftptr(selfp, tcre_mptr_cnt(tanatom,1));	//выделение указателей для tanjector
	
	//tcre_fref(&self->self, self);							//ссылка на себя
	
	tlist_fcre(&self->relat);				//создаем список связей
	tinctor_fcre_strong(&self->effort, 0,0);//счетчик уровня принятого сигнала
	tinctor_fcre_strong(&self->freq, 0,0);	//счетчик частоты атома
	
	
	tdeb_fdeb3("tkvl_deb", __FILE__, __LINE__, "self=%p\r\n", self);
	
	//возвращаем результат
	return self;
}

tanatomp tanatom_fcre_lim_freq(tanatompp selfp, tlong effort_lim, tlong freq_lim)
{
	tdeb_fdeb3("tanatom_deb", __FILE__, __LINE__, "selfp=%p\r\n", selfp);
	
	tanatomp self=tcre_ftptr(selfp, tcre_mptr_cnt(tanatom,1));	//выделение указателей для tanjector
	
	//tcre_fref(&self->self, self);							//ссылка на себя
	
	tlist_fcre(&self->relat);							//создаем список связей
	tinctor_fcre_strong(&self->effort, effort_lim,0);	//счетчик уровня принятого сигнала
	tinctor_fcre_strong(&self->freq, freq_lim,0);		//счетчик частоты атома
	
	
	tdeb_fdeb3("tkvl_deb", __FILE__, __LINE__, "self=%p\r\n", self);
	
	//возвращаем результат
	return self;
}

//выделение памяти под данные библиотеки
tanatomp tanatom_fcre_core_lim_freq(tanatompp selfp, tp core, tlong effort_lim, tlong freq_lim)
{
	tdeb_fdeb3("tanatom_deb", __FILE__, __LINE__, "selfp=%p\r\n", selfp);
	
	tanatomp self=tcre_ftptr(selfp, tcre_mptr_cnt(tanatom,1));	//выделение указателей для tanjector
	
	//tcre_fref(&self->self, self);							//ссылка на себя
	
	tlist_fcre(&self->relat);							//создаем список связей
	tcre_fref(&self->core, core);						//ядро атома
	tinctor_fcre_strong(&self->effort, effort_lim,0);	//счетчик уровня принятого сигнала
	tinctor_fcre_strong(&self->freq, freq_lim,0);		//счетчик частоты атома
	
	
	tdeb_fdeb3("tkvl_deb", __FILE__, __LINE__, "self=%p\r\n", self);
	
	//возвращаем результат
	return self;
	
}

tanatomp tanatom_frelat(tanatompp selfp, tanatomp atom)		//добавление связи на атом
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
	tanatomp self=*selfp;
	
	if (!atom)
	{
		return NULL;
	}
	//***проверка входных данных
	
	//*** создаем и добавляем связь
	
	tlist_fadd_item(&self->relat, tlisti_fcre(NULL, atom));
	
	//*** создаем и добавляем связь
	
}

tanatomp tanatom_femit(tanatompp selfp)   //выполняем излучение
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
	tanatomp self=*selfp;
	//***проверка входных данных
	
	//*** излучение
	
	if (tinctor_femit(&self->effort))		//если превышен предел текущего атома
	{										//атом начинает излучать
		tlist_eachp list_each=tlist_each_fcre(NULL, self->relat);	//перебор связей
		while(tlist_each_finc(&list_each))
		{
			tanatom_finc((tanatompp)&list_each->listi->data);	//инкрементация связанного атома
			tanatom_femit((tanatompp)&list_each->listi->data);	//запрос на излучение связанного атома
		}
	}
	
	//*** излучение
}


tanatomp tanatom_finc(tanatompp selfp)		//инкрементация effort->val
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
	tanatomp self=*selfp;
	//***проверка входных данных
	
	tinctor_finc(&self->effort);	//инкрементируем текущий уровень сигнала
}

