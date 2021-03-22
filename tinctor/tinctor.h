//tinctor.h 

/*
 * programing by dnclive(c)2011
 *  dnclive@gmail.com
*/
#ifndef tinctorh
#define tinctorh

#include <stdlib.h>
#include <stdio.h>

#include <tdeb.h>
#include <tcontext.h>
#include <tcre.h>
#include <tstr.h>
#include <tmem.h>
#include <tlist.h>
#include <tlist_each.h>

typedef struct _tinctor tinctor ;

typedef tinctor * tinctorp ;

typedef tinctor ** tinctorpp ;

//данные
struct _tinctor
{
	tlongp val;		//текущее значение
	tlongp lim;		//предельное значение превышение которого вызывает функцию femit
	//tmed med;		//среднее значение
};


//**********функции*************

/*
	int tinctor_fcre_flex(tinctorpp selfp, long lim, long val, float sens)
	функция:
		инициализирует структуру инкрементатора self, присваивая self->lim=lim, self->val=val
		self->sens=sens
		Пример: 
			
	параметры:
		*self - указатель на структуру инкрементатора (иметирует указатель this в объектах)
		lim - начальное значение предела инкрементатора
		val - инициализация текущего значения
		sens - чувствиетльность к изменению текущего значения, скорость изменения предела
		
	эффект:
		функция инициализирует переменные структуры, инициализирует структуру tmed	
		вычисляющую среднее значение приходащих val
	возврат:
		функция возвращает 0 если инициализация прошла успешно
*/
tinctorp tinctor_fcre_flex(tinctorpp selfp, tlong lim, tlong val, tfloat sens);	//функция инициализации структуры

/*
	int tinctor_fcre_strong(tinctorpp selfp, long lim, long val)
	функция:
		инициализирует структуру инкрементатора self, присваивая self->lim=lim, self->val=val
		self->sens=sens
		Пример: 
			
	параметры:
		*self - указатель на структуру инкрементатора (иметирует указатель this в объектах)
		lim - начальное значение предела инкрементатора
		val - инициализация текущего значения
		sens - чувствиетльность к изменению текущего значения, скорость изменения предела
		
	эффект:
		функция инициализирует переменные структуры, инициализирует структуру tmed	
		вычисляющую среднее значение приходащих val
	возврат:
		функция возвращает 0 если инициализация прошла успешно
*/
tinctorp tinctor_fcre_strong(tinctorpp selfp, tlong lim, tlong val);	//функция инициализации структуры

/*
	int tinctor_finc(tinctorpp selfp)
	функция:
		инерементирует self->val++ и возвращает новое значение self->val
		Пример: 
			
	параметры:
		*self - указатель на структуру инкрементатора (иметирует указатель this в объектах)
		
	эффект:
		инерементирует self->val++ и возвращает новое значение self->val
	возврат:
		функция возвращает self->val
*/
tinctorp tinctor_finc(tinctorpp selfp);							//функция инкрементирующая текущее значение

/*
	int inctor_fincn(tinctor *self, long n)
	функция:
		увеличивает ткущее значение на n self->val+=n и возвращает новое значение self->val
		Пример: 
			
	параметры:
		*self - указатель на структуру инкрементатора (иметирует указатель this в объектах)
		n - значение приращения self->val
		
	эффект:
		увеличивает ткущее значение на n self->val+=n и возвращает новое значение self->val
	возврат:
		функция возвращает self->val
*/
tinctorp tinctor_fincn(tinctorpp selfp, tlong n);				//функция инкрементирующая текущее значение на n

/*
	int inctor_femit(tinctor *self)
	функция:
		осуществляет проверку условия self->val>=self->lim если условие истинно то возвращает 1 иначе 0
		суть проверка превышает ли текущее значение пределльное елси дат то необходимо излучать
		Пример: 
			
	параметры:
		*self - указатель на структуру инкрементатора (иметирует указатель this в объектах)
		
	эффект:
		может быть получена информация нужно ли излучать
	возврат:
		функция возвращает 1 - если значение превышено или 0 - если нет
*/
tlong tinctor_femit(tinctorpp selfp);					//функция возаврщает 1 если текущее значение первысило предел

/*
	int inctor_freset(tinctor *self)
	функция:
		сбрасывает текущее значение в 0
		Пример: 
			
	параметры:
		*self - указатель на структуру инкрементатора (иметирует указатель this в объектах)
		
	эффект:
		используется для сброса значения после излечения (превышения максимально допустимого)
	возврат:
		функция возвращает 0
*/
tinctorp tinctor_freset(tinctorpp selfp);					//функция сбрасывающая текущее значение в 0

/*
	int inctor_ftobestable(tinctor *self)
	функция:
		фукнция фиксирует текущее значение (заносит в med med_ffixmed) и получает новое среднее 
		с учетом фиксированного значения med_fval, если среднее значение больше 0 то оно заносится
		в self->lim то есть устанавливается новый предел излучения
		Пример: 
			
	параметры:
		*self - указатель на структуру инкрементатора (иметирует указатель this в объектах)
		
	эффект:
		есть функция адаптации предела к среднему значению поступающих значения
	возврат:
		функция возвращает новый предел self->lim
*/
tinctorp tinctor_ftobestable(tinctorpp selfp);					//функция фиксирующа текущее значение и вычислчющяя среднее


#endif