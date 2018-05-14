/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gene.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 22:22:50 by scollet           #+#    #+#             */
/*   Updated: 2017/07/16 14:39:57 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gene.h"

unsigned int   optimal(unsigned int *arr, int length)
{
  //int   fit;
  //unsigned int i = -1;
  //while (++i < (unsigned int)length)
  //  printf("arr : %d\n", arr[i]);
  //fit = rand() % length;
  //fit = arr[fit];
  //printf("fit : %d\n", fit);
  //printf("arr %d\n", arr[fit]);
  int   i = -1;
  int   highest = -1;
  int   *count;
  int   ret = -1;

  length = 0;
  count = (int*)calloc(100, sizeof(int));
  while (++i < 100)
  {
  //  printf("%d\n", arr[i]);
    count[arr[i]] += (arr[i] == 0) ? 0 : 1;
    //count[arr[i]] += 1;//arr[i];
    //printf("count[arr[i]] : %d\n", count[arr[i]]);
  }
  i = -1;
  while (++i < 100)
  {
    if (count[i] > highest)
    {
      highest = count[i];
      ret = i;
    }
  }
  //printf("ret : %d\n", arr[ret]);
//  printf("exit?\n");
  return (ret);
}

t_organism cross(int *water, int *sun)
{
  t_organism  offspring;
  int         i;
  int         bit;
  //t_cell      *root;

  i = -1;
  offspring = *(t_organism*)calloc(1, sizeof(t_organism));
  offspring = create_organism(0);
  //root = (t_cell*)calloc(1, sizeof(t_cell));
  bit = 0;
  *water = 0;
  while (++i < DEPTH)
  {
    //if (--sc > 0 && bit == 1)
    //{
    if (!(offspring.cell[i].gene.x = (sun[i] & water[i])))
    {
      if ((offspring.cell[i].gene.y = (sun[i] & random_gene())))
        offspring.cell[i].gene.z = water[i] ^ random_gene();
    }
    else if ((offspring.cell[i].gene.y = sun[i]))
    {
      offspring.cell[i].gene.z = random_gene();
    }
    //printf("%d, %d\n", offspring.cell->gene.x, offspring.cell->gene.y);
    //if (!offspring.cell)
	  //{
    //  offspring.cell->next = create_cell(offspring.ID, offspring.cell->root);
	  //	offspring.cell->next->next = 0;
	  //}
	  //offspring.cell = offspring.cell->next;
      //bit = 0;
  //  }
  //  else if (--wc > 0 && bit == 0)
  //  {
      //if (offspring.cell->next)
      //{
      //  offspring.cell = offspring.cell->next;
      //}
      //else
      //{
      //  offspring.cell->next = create_cell(offspring.ID);
      //  offspring.cell = offspring.cell->next;
      //}
      //offspring.cell->gene.x = *water++;
      //offspring.cell->gene.y = *water++;
      //if (offspring.cell->next)
      //  offspring.cell = offspring.cell->next;
      //else
      //  offspring.cell->next = create_cell(offspring.ID);
      //bit = 1;
  //  }
    //else
    //  bit = 1;
    //printf("offs : %d and iterator : %d\n", offspring.cell->ID, i);
    //++i;
  }
  //root = offspring.cell[0].gene.x;
  //offspring.cell = root;
  printf("do we leave cross?\n");
  return (offspring);
}
