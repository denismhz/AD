#include "SDL2/SDL.h"
#include <iostream>
#include <ctime>

void drawIntArray(int*, int, SDL_Renderer*, int m, int h);
void swap(int &a, int &b){
    int tmp = a;
    a = b; 
    b = tmp;
}

int getMax(int *arr, int l){
    int max = 0;
    for(int i = 0; i < l; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int main(){
    std::clock_t start = 0;
    double duration = 0;
    start = std::clock();

    int arr[10] = {10,2,5,11,12,6,14,8,8,9};

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* main = NULL;
    SDL_Renderer* renderer = NULL;

    main = SDL_CreateWindow("LOL", SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 1280, 960, SDL_WINDOW_SHOWN);
    if(!main){
        SDL_Log("%s", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(main, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        SDL_Log("%s", SDL_GetError());
        return 1;
    }

    int state = 0;
    int i = 10-1;
    int j = 0;
    while(1){
        duration = (std::clock() - start)/(double)CLOCKS_PER_SEC;
        SDL_Event event;
        drawIntArray(arr, 10, renderer, j, j+1);
        
        if(arr[j] > arr[j+1]){ 
            swap(arr[j], arr[j+1]);
        }
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                break;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                if(state == 0){
                    i--;
                    std::cout << i << "\n";
                    state = 1;
                    j = 0;
                }
                else if(state == 1){
                    if(j < i){
                        j++;
                    } else state = 0;
                } 
            }
        }
    }

    SDL_DestroyWindow(main);

    SDL_Quit();

    return 0;
}


void drawIntArray(int* arr, int l, SDL_Renderer* renderer, int m, int h){
    SDL_Rect rects[10];
    SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);
    SDL_RenderClear(renderer);
    int k = 100;
    for(int i = 0; i < l; i++){
        rects[i].w = 25;
        rects[i].h = arr[i] * 10;
        rects[i].x = i*30;
        rects[i].y = getMax(arr, l)*10 + (k - (rects[i].h -10));
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for(int i = 0; i < l; i++){
        SDL_RenderFillRect(renderer, &rects[i]);
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rects[m]);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rects[h]);

    SDL_RenderPresent(renderer);
}
