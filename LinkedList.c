/**
*	Mariano Seif
*	Curso: 1 F
*	Legajo: 110070
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = malloc(sizeof(LinkedList));
    this->pFirstNode = NULL;
    this->size = 0;

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* returnNode = NULL;
    int i;

	if(this!=NULL && nodeIndex<(this->size) && nodeIndex>-1){
    	if(nodeIndex==0){
    		returnNode=this->pFirstNode;
    	}else{
    		returnNode=this->pFirstNode;
    		for(i=0;i<nodeIndex;i++){
    			returnNode = returnNode->pNextNode;
    		}
    	}
    }
	return returnNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pPreviousNode;
    Node* pNewNode = (Node*) malloc(sizeof(Node));
    pNewNode->pElement = pElement;

    if(this!=NULL && nodeIndex>-1 && nodeIndex<((this->size)+1)){
    	if(nodeIndex==0){
    		pNewNode->pNextNode = this->pFirstNode;
    		this->pFirstNode = pNewNode;
    	}else if(nodeIndex<(this->size)){
    		pPreviousNode = getNode(this, nodeIndex-1);
    		pNewNode->pNextNode = pPreviousNode->pNextNode;
    		pPreviousNode->pNextNode = pNewNode;
    	}else if(nodeIndex==(this->size)){
    		pNewNode->pNextNode = NULL;
    		pPreviousNode = getNode(this, nodeIndex-1);
    		pPreviousNode->pNextNode = pNewNode;
    	}
    returnAux = 0;
    this->size++;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL){
    	if(addNode(this, this->size, pElement)==0){
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>-1 && index<(this->size)){
    	returnAux = (getNode(this, index))->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* node;

    if(this!=NULL && index>-1 && index<(this->size)){
    	node = getNode(this, index);
    	node->pElement=pElement;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* prevNode;
    Node* nextNode;

    if(this!=NULL && index>-1 && index<(this->size) && (this->size)>0){

    	if(this->size==1){
    		free(this->pFirstNode->pElement);
    		free(this->pFirstNode);
    		this->pFirstNode = NULL;
    	}else if(this->size>1 && index==0){
    		nextNode = getNode(this,1);
    		free(getNode(this,0)->pElement);
    		free(getNode(this,0));
    		this->pFirstNode = nextNode;
    	}else if(this->size>2 && index<(this->size-1)){
    		prevNode = getNode(this, index-1);
			nextNode = getNode(this, index+1);
			free(getNode(this,index)->pElement);
			free(getNode(this, index));
			prevNode->pNextNode = nextNode;
    	}else if(index==(this->size-1) && this->size>1){
    		prevNode = getNode(this,index-1);
    		free(getNode(this,index)->pElement);
    		free(getNode(this, index));
    		prevNode->pNextNode = NULL;
    	}

    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len, i;

    if(this!=NULL){
    	len = ll_len(this);
    	if(len>0){
			for(i=len-1;i>-1;i--){
				ll_remove(this,i);
			}
			this->size=0;
    	}
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
    	ll_clear(this);
    	free(this);
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int i, len;
	int returnAux = -1;

	if(this!=NULL){
		len = ll_len(this);
		if(len>0){
			for(i=0;i<len;i++){
				if(getNode(this,i)->pElement == pElement){
					returnAux=i;
					break;
				}
			}
		}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
    	returnAux = 1;
    	if(this->size>0){
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && index>-1 && index<this->size+1){
    	if(this->size==0){
    		if(addNode(this, 0, pElement)==0){
    			returnAux=0;
    		}
    	}else{
    		if(addNode(this, index, pElement)==0){
				returnAux=0;
			}
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && this->size>0 && index>-1 && index<this->size){
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int i, len;
	int returnAux = -1;

	if(this!=NULL){
		len = ll_len(this);
		returnAux=0;
		for(i=0;i<len;i++){
			if(ll_get(this,i) == pElement){
				returnAux=1;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int i, len2;
	int returnAux = -1;

	if(this!=NULL && this2!=NULL){
		len2 = ll_len(this2);
		returnAux=1;
		for(i=0;i<len2;i++){
			if(!ll_contains(this, getNode(this2,i)->pElement)){
				returnAux=0;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    int i;
	LinkedList* cloneArray = NULL;
    if(this!=NULL && from>-1 && from<this->size && to>from && to<this->size+1){
    	cloneArray = ll_newLinkedList();
    	for(i=from;i<to;i++){
    		ll_add(cloneArray, ll_get(this,i));
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	int i, len;
	LinkedList* cloneArray = NULL;
	if(this!=NULL){
		cloneArray = ll_newLinkedList();
		len = ll_len(this);
		for(i=0;i<len;i++){
			ll_add(cloneArray, ll_get(this,i));
		}
	}
	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i, j, len, condicion;
    void* pElement1;
    void* pElement2;

    if(this!=NULL && (order==0 || order==1) && pFunc!= NULL && this->size>1){
    	len = ll_len(this);
    	for(i=0;i<len-1;i++){
    		for(j=i+1;j<len;j++){
    			pElement1 = ll_get(this,i);
				pElement2 = ll_get(this,j);
				condicion = pFunc(pElement1, pElement2);

				if((order==1 && condicion==1) || (order==0 && condicion==-1)){
					ll_set(this,i,pElement2);
					ll_set(this,j,pElement1);
					}

				}
    	}
    	returnAux=0;
    }
    return returnAux;
}


int ll_count(LinkedList* this, int (*fn)(void* element))
{
    int acumulador = 0;
    int i, len, retornoFn;
    void* element;

    if(this!=NULL && fn!= NULL && this->size>0){
    	len = ll_len(this);
    	for(i=0;i<len;i++){
    		element = ll_get(this,i);
    		retornoFn = fn(element);
    		if(retornoFn!=-1){
    			acumulador += retornoFn;
    		}
    	}
    }else{
    	acumulador = -1;
    }
    return acumulador;
}

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
    int i, len;
    void* element;
    LinkedList* retorno = NULL;
    LinkedList* nuevaLista = ll_newLinkedList();


    if(this!=NULL && fn!= NULL && this->size>0){
    	len = ll_len(this);
    	for(i=0;i<len;i++){
    		element = ll_get(this,i);
    		if(fn(element)){
    			ll_add(nuevaLista, element);
    		}
    	}
    	retorno = nuevaLista;
    }
    return retorno;
}

LinkedList* ll_filter2(LinkedList* this, int (*fn)(void* element, int idPiloto), int idPiloto)
{
    int i, len;
    void* element;
    LinkedList* retorno = NULL;
    LinkedList* nuevaLista = ll_newLinkedList();


    if(this!=NULL && fn!= NULL && this->size>0){
    	len = ll_len(this);
    	for(i=0;i<len;i++){
    		element = ll_get(this,i);
    		if(fn(element, idPiloto)){
    			ll_add(nuevaLista, element);
    		}
    	}
    	retorno = nuevaLista;
    }
    return retorno;
}
