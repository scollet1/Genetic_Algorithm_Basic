/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:28:10 by scollet           #+#    #+#             */
/*   Updated: 2017/07/13 11:20:15 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gene.h"

/*
t_cell  ***map(t_cell domain[DEPTH][100][100])
{
  int   j;
  int   i;
  //domain = (t_cell**)calloc(1, sizeof(*t_cell));
  for (i = 0; i < 100; i++)
  {
    domain[i] = (t_cell**)calloc(100, sizeof(t_cell));
    for (j = 0; j < 100; j++)
      domain[i][j] = (t_cell*)calloc(100, sizeof(t_cell));
  }
  return (domain);
}
*/
/*
t_cell  *copy_cell(t_cell *source)
{
  t_cell *cell;

  cell = (t_cell*)calloc(1, sizeof(t_cell));
  cell->gene = *(t_vector*)calloc(1, sizeof(t_vector));
  //cell->root_cell = (t_cell*)calloc(1, sizeof(t_cell));
  cell->next = (t_cell*)calloc(1, sizeof(t_cell));
  //printf("copy.0\n");
  //cell->root_cell = cell;
  //printf("copy.1\n");
  cell->ID = source->ID;
  //printf("copy.2\n");
  cell->root = source->root;
  //printf("copy.3\n");
  cell->gene.x = source->gene.x;
  cell->gene.y = source->gene.y;
  //printf("%d, %d\n", source->gene.x, source->gene.y);
  //printf("copy.5\n");
  if (source->next)
    cell->next = copy_cell(source->next);
  cell->next = 0;
  printf("exit copy\n");
  return (cell);
}
*/
t_cell  create_cell(unsigned int uid, int root)
{
  t_cell cell;

  cell = *(t_cell*)calloc(1, sizeof(t_cell));
  cell.gene = *(t_vector*)calloc(1, sizeof(t_vector));
  cell.ID = uid;
  cell.root = root;
  //printf("seg before creat cell\n");
  if (uid == 100 || uid == 102)
  {
    cell.gene.x = 0;
    cell.gene.y = 0;
    cell.gene.z = 0;
  }
  else if (uid == 101)
  {
    cell.gene.x = 0;
    cell.gene.y = 1;
    cell.gene.z = 0;
  }
  else if (cell.ID < 100)
  {
    cell = mutate(cell);
  }
  //printf("left this\n");
  return (cell);
}

t_organism  create_organism(unsigned int uid)
{
  t_organism organism;
  int i;

  organism = *(t_organism*)calloc(1, sizeof(t_organism));
  for (i = 0; i < LOOK; i++)
    organism.cell[i] = create_cell(uid, 1);
  organism.ID = uid;
//  printf("left this\n");
  return (organism);
}

t_population  *spawn_new(t_population *population)
{
  int   uid;
  int   i;
  //t_cell *root;
  //t_cell *root2;

  uid = 0;
  //root = (t_cell*)calloc(1, sizeof(t_cell));
  //root2 = (t_cell*)calloc(1, sizeof(t_cell));
  //population->organism[0] = *offspring;
  //free(&offspring);
  //offspring->cell->gene.x = 0;
  while (++uid < WIDTH)
  {
    population->organism[uid].ID = uid;
    //printf("go to create\n");
    population->organism[uid] = create_organism(population->organism[uid].ID);
  //  printf("enter?\n");
    for (i = 0; i < LOOK; i++)
    {
      //printf("%d\n", i);
      population->organism[uid].cell[i].gene.x = population->organism[0].cell[i].gene.x;
      population->organism[uid].cell[i].gene.y = population->organism[0].cell[i].gene.y;
      population->organism[uid].cell[i].gene.z = population->organism[0].cell[i].gene.z;
      population->organism[uid].cell[i].ID = uid;
      population->organism[uid].cell[i] = population->organism[uid].cell[i];
      population->organism[0].cell[i] = population->organism[0].cell[i];
    }
  }
  //printf("leave?\n");
  return (population);
}

t_population   *init(t_population *population)
{
  int   uid;

  uid = -1;
  while (++uid < WIDTH)
     population->organism[uid] = create_organism(uid);
  population->organism[0].height = 89;
  //printf("okay\n");
  return (population);
}

t_population  *re_init(t_population *population)
{
  population->open = create_organism(100);
  population->sun = create_organism(101);
  population->water = create_organism(102);
  return (population);
}

int   spawn(t_cell domain[DEPTH][HEIGHT][WIDTH], t_population *population, int height)
{
  int   x;
  int   y;
  int   z;

  z = 0;
  while (z < DEPTH)
  {
    //system("clear");
    //display(domain);
    y = 0;
    while (y < HEIGHT)
    {
      x = 0;
      while (x < WIDTH)
      {

        //printf("%d\n", height);
        if (y == height)
        {
          domain[z][y][x] = population->sun.cell[0];
        }
        else if (y == 90)
        {
          domain[z][y][x] = population->organism[x].cell[z];
          domain[z][y][x].root = x;
          //printf("%d\n", domain[y][x]->ID);
          //printf("%d, %d\n", domain[y][x]->gene.x, domain[y][x]->gene.y);
        }
        else if (y == 99)
        {
          domain[z][y][x] = population->water.cell[0];
        }
        else
        {
          domain[z][y][x] = population->open.cell[0];
        }
        ++x;
      }
      ++y;
      //printf("%d\n", y);
    }
    ++z;
  }
  display(domain);
  //exit(0);
  //population->organism->cell = root;
  printf("Leave?\n");
  //display(domain);
  //exit(1);
  return (1);
}
