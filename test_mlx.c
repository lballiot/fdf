#include <mlx.h>
#include <fcntl.h>
#include "libft/libft.h"

int main(int ac, char **av)
{
	void *mlx_ptr;
	void *window;
	int x = 100;
	int y = 100;
	int x_centre;
	int y_centre;
	int m;
	int rayon;

	if (ac != 2)
	{
		ft_putstr("Usage : ./fdf <filename> [ map ]\n");
		exit(EXIT_FAILURE);
	}
	mlx_ptr = mlx_init(); // init obligatory
	window = mlx_new_window(mlx_ptr, 500, 500, av[1]); // open window to see the map
// square
	while (x < 400)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 0xFFFFFF);
		x++;
	}
	while (y < 400)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 0xFFFFFF);
		y++;
	}
	while (x > 100)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 0xFFFFFF);
		x--;
	}
	while (y > 100)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 0xFFFFFF);
		y--;
	}
// triangle
	x = 250;
	y = 300;
	while (y > 250)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 0xFE0000);
		x++;
		y--;
	}
	printf("y = %d\n", y);
	while (y < 300)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 0xFE0000);
		x++;
		y++;
	}
	while (x > 250)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 0xFE0000);
		x--;
	}
// circle
	x = 0;
	y = 50;
	rayon = 50;
	x_centre = 200;
	y_centre = 200;
	m = 5 - 4*rayon;
	while (x <=y)
	{
		mlx_pixel_put(mlx_ptr, window, x+x_centre, y+y_centre, 0xFFFFF);
		mlx_pixel_put(mlx_ptr, window, y+x_centre, x+y_centre, 0xFFFFF);
		mlx_pixel_put(mlx_ptr, window, -x+x_centre, y+y_centre, 0xFFFFF);
		mlx_pixel_put(mlx_ptr, window, -y+x_centre, x+y_centre, 0xFFFFF);
		mlx_pixel_put(mlx_ptr, window, x+x_centre, -y+y_centre, 0xFFFFF);
		mlx_pixel_put(mlx_ptr, window, y+x_centre, -x+y_centre, 0xFFFFF);
		mlx_pixel_put(mlx_ptr, window, -x+x_centre, -y+y_centre, 0xFFFFF);
		mlx_pixel_put(mlx_ptr, window, -y+x_centre, -x+y_centre, 0xFFFFF);
		if (m > 0)
		{
			y--;
			m = m - 8*y;
		}
		x++;
		m = m + 8*x+4;
	}

// octant
	x = 0;
	y = 25;
	rayon = 25;
	x_centre = 50;
	y_centre = 50;
	m = 5 - 4*rayon;
	while (x <=y)
	{
		mlx_pixel_put(mlx_ptr, window, x+x_centre, y+y_centre, 0x28B212);
		if (m > 0)
		{
			y--;
			m = m - 8*y;
		}
		x++;
		m = m + 8*x+4;
	}

	mlx_loop(mlx_ptr);
	return (0);
}


/*

///////////////////////////////////////////////////////////////////////////////

x <- 0
y <- r
m <- r - 1

while (y >= x)
{
mlx_pixel_put(mlx_ptr, window, x + x_centre, y + y_centre, 0xE4FD00);
mlx_pixel_put(mlx_ptr, window, y + x_centre, x + y_centre, 0xE4FD00);
mlx_pixel_put(mlx_ptr, window, -x + x_centre, y + y_centre, 0xE4FD00);
mlx_pixel_put(mlx_ptr, window, -y + x_centre, x + y_centre, 0xE4FD00);
mlx_pixel_put(mlx_ptr, window, x + x_centre, -y + y_centre, 0xE4FD00);
mlx_pixel_put(mlx_ptr, window, y + x_centre, -x + y_centre, 0xE4FD00);
mlx_pixel_put(mlx_ptr, window, -x + x_centre, -y + y_centre, 0xE4FD00);
mlx_pixel_put(mlx_ptr, window, -y + x_centre, -x + y_centre, 0xE4FD00);
if (m >= 2*x)
{
m = m - 2*x - 1;
x++;
}
else if (m < 2*(rayon - y))
{
m = m + 2*y - 1;
y--;
}
else 
{
m = m + 2*(y-x-1);
y--;
x++;
}
}

////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

procédure tracerOctant (entier rayon, entier x_centre, entier y_centre)
        déclarer entier x, y, m ;
        x ← 0 ;
        y ← rayon ;                 // on se place en haut du cercle 
        m ← 5 - 4*rayon ;           // initialisation
        Tant que x <= y             // tant qu'on est dans le second octant
                tracerPixel( x+x_centre, y+y_centre ) ;
                si m > 0 alors      // choix du point F
                        y ← y - 1 ;
                        m ← m-8*y ; // correspond au "d" des explications
                fin si ;
                x ← x+1 ;
                m ← m + 8*x+4 ;
        fin tant que ;
fin de procédure ;

/////////////////////////////////////////////////////////////////////////////

procédure tracerCercle (entier rayon, entier x_centre, entier y_centre)
        déclarer entier x, y, m ;
        x ← 0 ;
        y ← rayon ;             // on se place en haut du cercle 
        m ← 5 - 4*rayon ;       // initialisation
        Tant que x <= y         // tant qu'on est dans le second octant
                tracerPixel( x+x_centre, y+y_centre ) ;
                tracerPixel( y+x_centre, x+y_centre ) ;
                tracerPixel( -x+x_centre, y+y_centre ) ;
                tracerPixel( -y+x_centre, x+y_centre ) ;
                tracerPixel( x+x_centre, -y+y_centre ) ;
                tracerPixel( y+x_centre, -x+y_centre ) ;
                tracerPixel( -x+x_centre, -y+y_centre ) ;
                tracerPixel( -y+x_centre, -x+y_centre ) ;
                si m > 0 alors       //choix du point F
                        y ← y - 1 ;
                        m ← m - 8*y ;
                fin si ;
                x ← x + 1 ;
                m ← m + 8*x + 4 ;
        fin tant que ;
fin de procédure ;

*/
