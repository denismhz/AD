#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include "button.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 960

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
    srand(time(NULL));
    int arr[10] = {10,2,5,11,12,6,14,8,8,9};
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 20;
    }
    
    if(TTF_Init() < 0){
        SDL_Log("Unable to initialize TTF: %s", TTF_GetError());
        return 1;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }
    SDL_Color black = {0,0,0};
    SDL_Window* main = NULL;
    SDL_Renderer* renderer = NULL;
    main = SDL_CreateWindow("LOL", SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(main, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* font = TTF_OpenFont("OpenSans-Light.ttf", 12);
    SDL_Color white = {0, 0, 255};
    SDL_Color a = {127, 127, 127, 255};
    Button* b = new Button(130, 30, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 
            "Next Step", font, black, a, renderer);
    Button* randomize = new Button(130, 30, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 
            "Randomize", font, black, a, renderer);

    SDL_Rect message_rect;
    message_rect.x = 0;
    message_rect.y = 0;
    message_rect.w = 500;
    message_rect.h = 40;
    SDL_Rect message_rect2;
    message_rect2.x = 0;
    message_rect2.y = 0;
    message_rect2.w = 200;
    message_rect2.h = 40;


    SDL_Rect rects[10];
    SDL_Rect indeces[10];
    SDL_Rect nums[10];
    SDL_Surface* indexS[10];
    SDL_Surface* numS[10];
    SDL_Texture* numT[10];
    SDL_Texture* indexT[10];

    SDL_Surface* indexSurface = TTF_RenderText_Solid(font, "Index[j]:", black);
    SDL_Texture* indexTex = SDL_CreateTextureFromSurface(renderer, indexSurface);

    SDL_Rect indecesTextRect;
    indecesTextRect.w = 100;
    indecesTextRect.h = 30;

    int state = 1;
    int reset = 0;
    int i = 10-1;
    int j = 0;
    int l = 10;
    int down = 0;
    string txt2;
    stringstream sstm;
        SDL_Surface* message_surface;
        SDL_Texture* message_texture;
        string txt = "Compare if Array[ " + to_string(j) + "] is greater than Array[ "+to_string((j+1))  + "]";
        message_surface = TTF_RenderText_Solid(font, txt.c_str(), white);
        message_texture = SDL_CreateTextureFromSurface(renderer, message_surface);
        SDL_Surface* message2_surface;
        SDL_Texture* message2_texture;
    while(1){
        if(arr[j] > arr[j+1]){ 
            txt2 = "TRUE -> swap";
            message2_surface = TTF_RenderText_Solid(font, txt2.c_str(), white);
            message2_texture = SDL_CreateTextureFromSurface(renderer, message2_surface);
        }
        SDL_Event event;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        if(reset){
            for(int i = 0; i < 10; i++){
                arr[i] = rand() % 20;
            }
            i = 10-1;
            j = 0;
            reset = 0;
        }
        int k = 100;
        for(int i = 0; i < l; i++){
            nums[i].w = 30;
            nums[i].h = 30;
            nums[i].x = i*45 + SCREEN_WIDTH/2 - 225 + 5;
            nums[i].y =getMax(arr, l)*10 + (k - (rects[i].h -10))+arr[i]*10+35;
            indeces[i].w = 30;
            indeces[i].h = 30;
            indeces[i].x = i*45 + SCREEN_WIDTH/2 - 225 + 5;
            indeces[i].y =getMax(arr, l)*10 + (k - (rects[i].h -10));
            rects[i].w = 40;
            rects[i].h = 30+arr[i] * 10;
            rects[i].x = i*45 + SCREEN_WIDTH/2 - 225;
            rects[i].y = getMax(arr, l)*10 + (k - (rects[i].h -10));
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        for(int i = 0; i < l; i++){
            SDL_RenderFillRect(renderer, &rects[i]);
        }
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rects[j]);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rects[j+1]);
        for(int i = 0; i < l; i++){
            string s = to_string(arr[i]);
            SDL_Color lol = {255,255,255};
            indexS[i] = TTF_RenderText_Solid(font, s.c_str(), lol);
            indexT[i] = SDL_CreateTextureFromSurface(renderer, indexS[i]);
            SDL_RenderCopy(renderer, indexT[i], NULL, &indeces[i]);
            s = to_string(i);
            numS[i] = TTF_RenderText_Solid(font, s.c_str(), black);
            numT[i] = SDL_CreateTextureFromSurface(renderer, numS[i]);
            SDL_RenderCopy(renderer, numT[i], NULL, &nums[i]);
        }

        indecesTextRect.x = nums[0].x - 150;
        indecesTextRect.y = nums[0].y;
        b->rect.x = nums[0].x;
        b->rect.y = nums[0].y + 40;
        randomize->rect.x = b->rect.x + b->rect.w + 30;
        randomize->rect.y = b->rect.y;
        message_rect.x = b->rect.x;
        message_rect.y = b->rect.y + message_rect.h;
        message_rect2.x = b->rect.x;
        message_rect2.y = message_rect.y + message_rect2.h;
        if(state == 0 && i >= 0){
            i--;
            state = 1;
            j = 0;
        }
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                break;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                int x, y;
                SDL_GetMouseState(&x, &y);
                if(x > b->rect.x && y > b->rect.y && b->rect.x + b->rect.w > x && b->rect.y +b->rect.h >y)
                {
                    down = 1;
                } else down = 0;
                if(state == 1 && down){
                    if(arr[j] > arr[j+1]){ 
                        state = 2;
                    }   
                    if(j < i && state == 1 && down){
                        j++;
                        string txt = "Compare if Array[ " + to_string(j) + "] is greater than Array[ "+to_string((j+1))  + "]";
                        message_surface = TTF_RenderText_Solid(font, txt.c_str(), white);
                        message_texture = SDL_CreateTextureFromSurface(renderer, message_surface);
                    }
                }
                if(state == 2 && down){
                    swap(arr[j], arr[j+1]);
                    txt2 = "";
                    message2_surface = TTF_RenderText_Solid(font, txt2.c_str(), white);
                    message2_texture = SDL_CreateTextureFromSurface(renderer, message2_surface);
                    state = 1;
                }
                if(j >= i) state = 0;
                if(x > randomize->rect.x && y > randomize->rect.y && randomize->rect.x + randomize->rect.w > x && randomize->rect.y +randomize->rect.h >y)
                {
                    reset = 1;
                } else reset = 0;;
            }
        }
        sstm.str(std::string());
        b->render();
        randomize->render();
        SDL_RenderCopy(renderer, message_texture, NULL, &message_rect);
        SDL_RenderCopy(renderer, message2_texture, NULL, &message_rect2);
        SDL_RenderCopy(renderer, indexTex, NULL, &indecesTextRect);
        SDL_RenderPresent(renderer);
        for(int i = 0; i < l; i++){
            SDL_FreeSurface(indexS[i]);
            SDL_DestroyTexture(indexT[i]);
            SDL_FreeSurface(numS[i]);
            SDL_DestroyTexture(numT[i]);
        }
    }
    SDL_DestroyTexture(message_texture);
    SDL_FreeSurface(message_surface);
    SDL_DestroyTexture(message2_texture);
    SDL_FreeSurface(message2_surface);
    b->freeButton();
    randomize->freeButton();
    TTF_CloseFont(font);
    SDL_FreeSurface(indexSurface);
    SDL_DestroyTexture(indexTex);
    SDL_DestroyWindow(main);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
