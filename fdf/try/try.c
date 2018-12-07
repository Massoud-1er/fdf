#include <mlx.h>
#include <unistd.h>
#include "../src/libft/libft.h"

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    int xi, yi, xf, yf;


    int dx, dy, i, xinc, yinc, cumul, x, y;
    
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
    yi = 100;
    yf = 20;
    xi = 40;
    xf = 40;

    x = xi ;
    y = yi ;
    dx = xf - xi ;
    dy = yf - yi ;
    xinc = ( dx > 0 ) ? 1 : -1;
    yinc = ( dy > 0 ) ? 1 : -1;
    dx = ft_abs(dx);
    dy = ft_abs(dy);
    mlx_pixel_put(mlx_ptr, win_ptr, x, y, 16777215);
    if ( dx > dy )
    {
        cumul = dx / 2 ;
        for ( i = 1 ; i <= dx ; i++ ) 
        {
            x += xinc ;
            cumul += dy ;
            if ( cumul >= dx )
            {
                cumul -= dx ;
                y += yinc ;
            }
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 16777215);
        } 
    }
    else
    {
      cumul = dy / 2;
      for ( i = 1 ; i <= dy ; i++ )
      {
        y += yinc ;
        cumul += dx ;
        if ( cumul >= dy )
        {
          cumul -= dy;
          x += xinc;
        }
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 16777215);
      }
    }
    mlx_loop(mlx_ptr);
    return (0);
}