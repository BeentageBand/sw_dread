/*=====================================================================================*/
/**
 * vector_it.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#ifndef VECTOR_IT_H_
#define VECTOR_IT_H_
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "vector.h"
#include "iterator.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Define Macros
 *=====================================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

#define VECTOR_IT_CTOR(PARAM) PARAM(Vector, iterable)
/*=====================================================================================* 
 * Exported Type Declarations
 *=====================================================================================*/
Declare_Class_Inherits(
      VectorIt, Iterator,
      VECTOR_IT_CTOR,
      ,);
/*=====================================================================================* 
 * Exported Object Declarations
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Function Prototypes
 *=====================================================================================*/
extern Iterator VectorIt_copy_it(VectorIt obj);
extern void * VectorIt_access_it(VectorIt obj);
extern void VectorIt_incremente_it(VectorIt obj);
extern bool_t VectorIt_has_next(VectorIt obj);
extern void VectorIt_get_next(VectorIt obj);
extern void VectorIt_set_it(VectorIt obj, void const * data);
extern void VectorIt_rm_it(VectorIt obj);
/*=====================================================================================* 
 * Exported Function Like Macros
 *=====================================================================================*/
#ifdef __cplusplus
}
#endif
/*=====================================================================================* 
 * vector_it.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*VECTOR_IT_H_*/
