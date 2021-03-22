//      tanatom_deb.c
//      
//      Copyright 2011 dnclive <dnclive@ubunlive3>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.


#include <stdio.h>

#include <tdeb.h>
#include <ctype.h>
#include <tstr.h>
#include "tanatom.h"

int main(int argc, char **argv)
{
	printf ("tanatom_deb_start\r\n");
	
	tdeb_finit("tanatom_deb");
	
	tanatomp anatom= tanatom_fcre(NULL);
	tanatomp anatom1= tanatom_fcre_lim_freq(NULL, 4, 4);
	tanatomp anatom2= tanatom_fcre_core_lim_freq(NULL, tcre_ftptr(NULL, 1), 3, 6);
	tanatomp anatom3= tanatom_fcre(NULL);
	
	//добавляем в anatom ссылку на anatom1
	tanatom_frelat(&anatom, anatom1);
	
	//добавляем в anatom ссылку на anatom2
	tanatom_frelat(&anatom, anatom2);
	
	
	//добавляем в anato1 ссылку на anatom3
	tanatom_frelat(&anatom1, anatom3);
	
	
	printf ("tanatom_deb_end\r\n");
	
	return 0;
}
