#include "SDL.h"
#include <SDL.h>

#include <EGL/egl.h>


#include <GLES/gl.h>

#include <SDL2/SDL.h>

    SDL_Window *win = NULL;

    SDL_Renderer *renderer = NULL;

    SDL_Texture *bitmapTex = NULL;

        SDL_Surface *surface;

        SDL_Rect rect, darea;

    SDL_Surface *bitmapSurface = NULL;
    
/*                     -----------
                               |
                               |
*/
void drawtriangle (SDL_Renderer *renderer)
{
	 int a;
	
  
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, 600, 200, 300, 240);
                SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
                SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
       
	
	}
		 int a=0,b=0,c=320,d=240;
	int s=0;
void line (SDL_Renderer *renderer)
{

  
                SDL_SetRenderDrawColor(renderer, s, 255, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, a, b, c, d);
               
                
       
	
	}



void

DrawChessBoard(SDL_Renderer * renderer)

{
	drawtriangle (renderer);

    int row = 0,column = 0,x = 0;

    SDL_Rect rect, darea;


    /* Get the Size of drawing surface */

    SDL_RenderGetViewport(renderer, &darea);


    for ( ; row < 8; row++) {

        column = row%2;

        x = column;

        for ( ; column < 4+(row%2); column++) {

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);


            rect.w = darea.w/8;

            rect.h = darea.h/8;

            rect.x = x * rect.w;

            rect.y = row * rect.h;

            x = x + 2;

            SDL_RenderFillRect(renderer, &rect);

        }

    }

}


int main(int argc, char *argv[]) {

      SDL_Init( SDL_INIT_EVERYTHING );
    int posX = 100, posY = 100, width = 320, height = 240;

           SDL_RenderFillRect(renderer, &rect);

  //  SDL_Init(SDL_INIT_VIDEO);


    win = SDL_CreateWindow("Hello World", posX, posY, width, height, SDL_WINDOW_OPENGL);

    surface = SDL_GetWindowSurface(win);

    renderer = SDL_CreateSoftwareRenderer(surface);

  

    SDL_RenderGetViewport(renderer, &darea);

             SDL_SetRenderDrawColor(renderer, 1, 0, 0, 0xFF);

    bitmapSurface = SDL_LoadBMP("hello.bmp");

    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);

    SDL_FreeSurface(bitmapSurface);
   // SDL_WM_SetCaption( "Zdarzenia", NULL );
  //  SDL_Flip( ekran );

    while (1) {

        SDL_Event e;

        if (SDL_PollEvent(&e)) {

            if (e.type == SDL_QUIT) {

                break;

            }

        }

         //   DrawChessBoard(renderer);
	drawtriangle (renderer);
	a++;
line(renderer);
    /* Got everything on rendering surface,

       now Update the drawing image on window screen */

    SDL_UpdateWindowSurface(win);

           SDL_RenderFillRect(renderer, &rect);        

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);

 //       SDL_RenderPresent(renderer);

                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
// turn on animate

   //     glClear(GL_COLOR_BUFFER_BIT);







    SDL_GL_SwapWindow(win);

    }


    SDL_DestroyTexture(bitmapTex);

    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(win);


    SDL_Quit();


    return 0;

}