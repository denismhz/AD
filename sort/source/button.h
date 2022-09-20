#ifndef _H_BUTTON_
#define _H_BUTTON_
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>

class Button{
    public:
        Button(int, int, int, int, const char*, TTF_Font*, SDL_Color, SDL_Color, SDL_Renderer*);
        void render();
        void isDown(SDL_Event* e);
        void freeButton();
        void setBackgroundColor(SDL_Color);
        SDL_Color backgroundColor;
        SDL_Rect rect;
        SDL_Renderer* renderer;
        SDL_Surface* buttonSurface;
        SDL_Texture* buttonTex;
        int down = 0;
};


Button::Button(int width, int height, int x, int y,const char* text, TTF_Font* font , SDL_Color color, SDL_Color backgroundColor, SDL_Renderer* renderer){
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = width;
    this->rect.h = height;
    this->renderer = renderer;
    this->backgroundColor = backgroundColor;
    this->buttonSurface = TTF_RenderText_Shaded(font, text, color, this->backgroundColor);
    this->buttonTex = SDL_CreateTextureFromSurface(renderer, buttonSurface);
}

void Button::isDown(SDL_Event* e){
}

void Button::render(){
    SDL_RenderCopy(this->renderer, this->buttonTex, NULL, &this->rect);
}

void Button::freeButton(){
    SDL_FreeSurface(buttonSurface);
    SDL_DestroyTexture(this->buttonTex);
}

#endif
