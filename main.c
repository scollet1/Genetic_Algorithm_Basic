/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:19:40 by scollet           #+#    #+#             */
/*   Updated: 2017/07/11 13:19:41 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gene.h"
#include <time.h>

void  error(err)
{
  exit(err);
}

int   main()
{
  //t_organism sun;
  //t_organism water;
  t_cell        domain[DEPTH][HEIGHT][WIDTH];
  t_population  *population;
  time_t        yes;
  //t_cell        *root;

  printf("test 0\n");
  srand((unsigned)time(&yes));
  printf("test 1\n");
  //domain = (t_cell***)calloc(DEPTH, sizeof(t_cell));
  population = (t_population*)calloc(1, sizeof(t_population));
  printf("test 2\n");
  population = init(population);
  //domain = map(domain);
  //printf("here?\n");
  //int   t;
  int   n;
  int height = 89;

  //for (t = 0; t < DEPTH0; t++)
  while (height > 1)
  {
    n = 0;
    //printf("highest: %d\n", highest);
    //printf("Time : t : %d\n", height);
    //printf("after re_init\n");
    population = re_init(population);
    //population = init(population);
    printf("sfault\n");
    spawn(domain, population, height);
    //height = population->organism[0].height;
    free(population);
    //for (int q = 0; q < 100; q++)
    //  free(population->organism[q]);
    population = (t_population*)calloc(1, sizeof(t_population));
    population->organism[0] = execute(domain, height);
    //system("clear");
    //display(domain);
    //free(domain);
    //domain = (t_cell***)calloc(100, sizeof(t_cell));
    printf("yes\n");

    population = spawn_new(population);
    //domain = map(domain);
    --height;

    /* NOTE : debuggin shit, don't trust any of it
    root = population->organism[0].cell;
    while (population->organism[0].cell->next)
    {
      n++;
      //printf("x : %d, y : %d\n", population->organism[0].cell->gene.x, population->organism[0].cell->gene.y);
      //population->organism[0].cell->gene.x =
      population->organism[0].cell = population->organism[0].cell->next;

    }
    printf("n = %d\n", n);
    population->organism[0].cell = root;*/
    //display(domain);
    //free(offspring);
    //population = init(population);
    //int f = -1;
    //while (++f < 100)
    //{
      //system("clear");
    //  printf("%d, %d\n", population->organism[0].cell->gene.x, population->organism[0].cell->gene.y);
    //}
  }
  if (population)
    free(population);
  return (0);
}
