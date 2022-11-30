/*
 * controller.h
 *
 *  Created on: 29 nov. 2022
 *      Author: PC
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFile(char* path,LinkedList* movieList);
int controller_saveFile(char* path,LinkedList* movieList);
int controller_printList(LinkedList* movieList);
int controller_setDuracion(LinkedList* movieList,LinkedList** movieListRating);
int controller_setGenero(LinkedList* movieList,LinkedList** movieListGenre);
int controller_filterGenero(LinkedList* movieList,LinkedList** arrayListGenre);
int controller_sortMovies(LinkedList* movieList);

#endif /* CONTROLLER_H_ */
