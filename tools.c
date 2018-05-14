/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 22:35:51 by scollet           #+#    #+#             */
/*   Updated: 2017/07/11 22:35:52 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gene.h"

int   random_gene()
{
  int   arr[3] = {-1, 0, 1};

  return (arr[(int)rand() % 3]);
}

unsigned int   *flush(unsigned int *water, int wc)
{
  unsigned int   *arr;
  int   i;
  int   j;

  wc = 0;
  arr = (unsigned int*)calloc(100, sizeof(unsigned int));
  j = 0;
  i = -1;
  while (++i < 100)
  {
    if (water[i] < 100)
      arr[i] = water[i];
    //printf("Water : %d, Arr : %d\n", water[i], arr[i]);
  }
  printf("Flushing... \n");
  return (arr);
}
