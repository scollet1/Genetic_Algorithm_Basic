/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rundm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:53:42 by scollet           #+#    #+#             */
/*   Updated: 2017/07/21 18:31:57 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gene.h"

/*

int   is_not_outside()
{
  return ()
}

*/

void  display(t_cell domain[DEPTH][HEIGHT][WIDTH])
{
  //int z = 0;
  for (int z = 0; z < 1; z++)
  {
    system("clear");
    for (int y = 0; y < 100; y++)
    {
      for (int x = 0; x < 100; x++)
      {
        if (domain[z][y][x].ID < 100)
        {
          //printf("ID %d\n",domain[z][y][x]->ID);
          printf("\x1B[%dm#\x1b[0m", (domain[z][y][x].ID % 8) + 31);
        }
        else if (domain[z][y][x].ID == 100)
          printf(".");
        else if (domain[z][y][x].ID == 101)
          printf("∆");
        else if (domain[z][y][x].ID == 102)
          printf("≈");
      }
      printf("\n");
    }
  }
  return ;
}

int   check_space(t_cell space, t_cell origin)
{
  int   clear;

  //if (!space)
  //  clear = 0;
  //else
    clear = (space.ID == 100 || space.ID == origin.ID) ? 1 : 0;
  //printf("clear ? %d\n", clear);
  return (clear);
}

t_cell  mutate(t_cell cell)
{
  //if ((cell->gene.x = random_gene()) == 0)
    cell.gene.x = random_gene();
    cell.gene.y = random_gene();
    cell.gene.z = random_gene();
  //else
  //  cell->gene.y = 0;
  //printf("mutate?\n");
  return (cell);
}

t_organism  mate(unsigned int sun, unsigned int water, t_cell domain[DEPTH][HEIGHT][WIDTH])
{
  /*
  ** TODO: Look up how to mate lmao
  */
  //t_organism *offspring;
  int   *watarr;
  int   *sunarr;
  int   i;
  int   j;
  int   x;
  int   y;
  int   z;

  //offspring = (t_organism*)calloc(1, sizeof(t_organism));
  //offspring->cell[0] = (t_cell*)calloc(1, sizeof(t_cell));
  //for (int i = 0; i < wc + sc; i++)
    //offspring[i].cell.gene = *(t_vector*)calloc(1, sizeof(t_vector));
  watarr = (int*)calloc(DEPTH, sizeof(int));
  sunarr = (int*)calloc(DEPTH, sizeof(int));
  i = -1;
  j = -1;
  z = 0;
  //printf("SUN %d WATER %d\n", sun, water);
  //water = 0;
  while (z < DEPTH)
  {
    y = 90;
    x = domain[z][y][x].root;
    while (y >= 0)
    {
      //if (domain[z][y][x]->ID == sun)
      //while (x >= 0)
      //{
        //if (domain[z][y][x]->next)
        //{
          //while (domain[z][y][x]->next)
          //{
            if (domain[z][y][x].ID == sun)
            {
              sunarr[i] = domain[z][y][x].gene.x;
              //printf("x %d, ", sunarr[i]);
              sunarr[i + 1] = domain[z][y][x].gene.y;
              //printf("y %d\n", sunarr[i + 1]);
              i += 2;
            }
            if (domain[z][y][x].ID == water)
            {
              watarr[j] = domain[z][y][x].gene.x;
              //printf("x %d, ", watarr[i]);
              watarr[j + 1] = domain[z][y][x].gene.y;
              //printf("y %d, \n", watarr[i + 1]);
              j += 2;
            }
            //domain[z][y][x] = domain[z][y][x]->next;
            //}
            //}
        --y;
      }
    ++z;
  }
  sunarr[++i] = 3;
  watarr[++j] = 3;
  printf("Leaving m8\n");
  return (cross(watarr, sunarr));
}

t_organism   execute(t_cell domain[DEPTH][HEIGHT][WIDTH], int height)
{
  int   x;
  int   y;
  int   z;
  unsigned int   *sun;
  int   sun_counter;
  unsigned int   *water;
  int   water_counter;
  //t_cell *root = (t_cell*)calloc(1, sizeof(t_cell));

  z = 0;
  sun = (unsigned int*)calloc(100, sizeof(unsigned int));
  sun_counter = 0;
  water = (unsigned int*)calloc(100, sizeof(unsigned int));
  water_counter = 0;
  while (sun_counter < 100)
  {
    display(domain);
    //if (sun_counter >= 100) break;
    //  if (sun_counter >= 100) break;
      y = 98;
      while (y >= 0)
      {
        //system("clear");
      //  if (sun_counter >= 100) break;
        x = 99;
        while (x >= 0)
        {
          //printf("4.1 && z = %d && y = %d && x = %d\n", z, y, x);
        //  printf("0.0\n");
          if ((check_space(domain[domain[z][y][x].gene.z + z][domain[z][y][x].gene.y + y][domain[z][y][x].gene.x + x],
                          domain[z][y][x]) == 1) &&
          ((domain[z][y][x].gene.y + y < HEIGHT - 1 && domain[z][y][x].gene.x + x < WIDTH) &&
          (domain[z][y][x].gene.y + y >= 1 && domain[z][y][x].gene.x + x >= 0)&&
          (domain[z][y][x].gene.z + z >= 0 && domain[z][y][x].gene.z + z < DEPTH - 1)))
          {
            //printf("1.0\n");
            if (domain[z][y][x].ID < 100)
            {
              //printf("1.1\n");
              domain[domain[z][y][x].gene.z + z][domain[z][y][x].gene.y + y][domain[z][y][x].gene.x + x] = domain[z + 1][90][domain[z][y][x].root];
              //domain[z][y][x] = create_cell(100, domain[z][y][x].root);
            }
          }
          else if (domain[z][y][x].ID < 100) /* If organism */
          {
          //  printf("2.0\n");
            if (domain[domain[z][y][x].gene.z + z][domain[z][y][x].gene.y + y][domain[z][y][x].gene.x + x].ID == 101)
            {
            //  printf("2.1\n");
              domain[domain[z][y][x].gene.z + z][domain[z][y][x].gene.y + y][domain[z][y][x].gene.x + x] = domain[z][y][x];
              sun[x] = domain[z][y][x].ID;
              ++sun_counter;
            }
            else if (domain[domain[z][y][x].gene.z + z][domain[z][y][x].gene.y + y][domain[z][y][x].gene.x + x].ID == 102)
            {
            //  printf("2.2\n");
              domain[domain[z][y][x].gene.z + z][domain[z][y][x].gene.y + y][domain[z][y][x].gene.x + x] = domain[z][y][x];
              water[x] = domain[z][y][x].ID;
              ++water_counter;
            }
            else if ((((x + 1 < 98) && (x - 1 > 0)) && domain[z][y][x + 1].ID != domain[z][y][x].ID) ||
                    (((y + 1 < 98) && (y - 1 > 1)) && domain[z][y - 1][x].ID != domain[z][y][x].ID) ||
                    (((x + 1 < 98) && (x - 1 > 1)) && domain[z][y][x - 1].ID != domain[z][y][x].ID) ||
                    (((z + 1 < DEPTH) && (z - 1 > 1)) && domain[z + 1][y][x].ID != domain[z][y][x].ID))
              domain[z][y][x] = mutate(domain[z][y][x]);//create_cell(domain[z][y][x]->ID, domain[z][y][x]->root);
          //  printf("2.4\n");
          }
          /* NOTE : I don't think I need this and I actually don't know what it's supposed to do */
          /* NOTE : I need this */
          /* NOTE : just kidding, this causes seg faults */
          else if (domain[z][y][x].ID == 101 && domain[domain[z][y][x].gene.z + z][domain[z][y][x].gene.y + y][domain[z][y][x].gene.x + x].ID < 100)
          {
          //  printf("3.0\n");
            domain[z][y][x] = domain[domain[z][y][x].gene.z + z][domain[z][y][x].gene.y + y][domain[z][y][x].gene.x + x];
            sun[x] = domain[z][y][x].ID;
            //printf("sun counter go up\n");
            ++sun_counter;
          }
        //  printf("4.0\n");
          --x;
        }
        --y;
      }
      printf("5.0\n");
  }
  //printf("do we leave?\n");
  //system("clear");

  display(domain);

  printf("exit with length : %d and %d and height : %d\n", sun_counter, water_counter, height);
  if (water_counter == 0)
    for (water_counter = 0; water_counter < 100; water_counter++)
      water[water_counter] = domain[0][90][water_counter].ID;
  printf("actually left\n");
  //exit(1);
  return (mate(optimal(sun, sun_counter), optimal(flush(water, water_counter),
          water_counter), domain));
}
