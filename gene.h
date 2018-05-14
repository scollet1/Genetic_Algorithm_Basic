/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gene.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:20:01 by scollet           #+#    #+#             */
/*   Updated: 2017/07/13 11:13:21 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENE_H
# define GENE_H
# include <stdlib.h>
# include <time.h>
# include <stdio.h>

# define DEPTH  20
# define HEIGHT 100
# define WIDTH  100
# define LOOK   DEPTH

int   highest;

typedef struct s_vector {
  int   x;
  int   y;
  int   z;
}              t_vector;

typedef struct s_cell {
  t_vector      gene;
  unsigned int  ID;
  int           root;
}              t_cell;

typedef struct s_organism {
  t_cell        cell[LOOK];
  unsigned int  ID;
  int           height;
  t_cell        *root;
}              t_organism;

typedef struct s_population {
  t_organism sun;
  t_organism water;
  t_organism organism[WIDTH];
  t_organism open;
  //t_organism *offspring;
}              t_population;

int           check_space(t_cell space, t_cell origin);
//t_cell        *copy_cell(t_cell *source);
t_cell        create_cell(unsigned int uid, int root);
t_organism    create_organism(unsigned int uid);
t_organism    cross(int *water, int *sun);
void 	        display(t_cell domain[DEPTH][HEIGHT][WIDTH]);
t_organism    execute(t_cell domain[DEPTH][HEIGHT][WIDTH], int height);
unsigned int  *flush(unsigned int *water, int wc);
t_population  *init(t_population *population);
t_cell        ***map(t_cell domain[DEPTH][HEIGHT][WIDTH]);
t_organism    mate(unsigned int sun, unsigned int water,
                t_cell domain[DEPTH][HEIGHT][WIDTH]);
t_cell        mutate(t_cell cell);
unsigned int  optimal(unsigned int *arr, int length);
int           random_gene();
t_population  *re_init(t_population *population);
int           spawn(t_cell domain[DEPTH][HEIGHT][WIDTH], t_population *population, int height);
t_population  *spawn_new(t_population *population);

#endif
