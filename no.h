#ifndef __NO_H_INCLUDED__
#define __NO_H_INCLUDED__

#include "vertice.h"

typedef struct No{
   struct vertice vert;
   struct No *prox;
} TipoNo;

#endif