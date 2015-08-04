/* 
 * File:   ActiveLanguage.h
 * Author: kevincando
 *
 * Created on July 22, 2015, 1:06 AM
 */

#ifndef ACTIVELANGUAGE_H
#define	ACTIVELANGUAGE_H

#ifdef	__cplusplus
extern "C" {
#endif

// Set to 1
#define ENGLISH 1
#define SPANISH 0

#define SET_LANG(X) #X
    
#define ACTIVE_LANGUAGE(X) SET_LANG(X)
    
#define DEFAULT_LANG ENGLISH
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* ACTIVELANGUAGE_H */

