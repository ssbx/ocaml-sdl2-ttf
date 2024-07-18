#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>

#include <SDL_ttf.h>
#include "ttf_stub.h"
#include "surface_stub.h"
#include "pixel_stub.h"

CAMLprim value
caml_TTF_Init(value unit)
{
    CAMLparam1(unit);
    int ret = TTF_Init();
    if (ret == -1)
        caml_failwith("caml_TTF_Init");

    CAMLreturn(Val_unit);
}

CAMLprim value
caml_TTF_Quit(value unit)
{
    CAMLparam1(unit);
    TTF_Quit();
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_TTF_OpenFont(value file, value ptsize)
{
    CAMLparam2(file, ptsize);
    TTF_Font * font = TTF_OpenFont((const char*) String_val(file), Int_val(ptsize));
    if (!font)
        caml_failwith("caml_TTF_OpenFont");
    CAMLreturn(Val_TTF_Font(font));
}

CAMLprim value
caml_TTF_CloseFont(value font)
{
    CAMLparam1(font);
    TTF_CloseFont(TTF_Font_val(font));
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_TTF_RenderText_Solid(value font, value text, value fg)
{
    CAMLparam3(font, text, fg);
    SDL_Color _fg;
    SDL_Color_val(&_fg, fg);
    SDL_Surface * surf = TTF_RenderText_Solid(
        TTF_Font_val(font),
        String_val(text),
        _fg);

    if (!surf)
        caml_failwith("caml_TTF_RenderText_Solid");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_TTF_RenderText_Blended(value font, value text, value fg)
{
    CAMLparam3(font, text, fg);
    SDL_Color _fg;
    SDL_Color_val(&_fg, fg);
    SDL_Surface * surf = TTF_RenderText_Blended(
        TTF_Font_val(font),
        String_val(text),
        _fg);

    if (!surf)
        caml_failwith("caml_TTF_RenderText_Blended");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_TTF_RenderText_Blended_Wrapped(
    value font,
    value text,
    value fg,
    value wraplength)
{
    CAMLparam4(font, text, fg, wraplength);
    SDL_Color _fg;
    SDL_Color_val(&_fg, fg);
    SDL_Surface * surf = TTF_RenderText_Blended_Wrapped(
        TTF_Font_val(font),
        String_val(text),
        _fg,
        Int32_val(wraplength));

    if (!surf)
        caml_failwith("caml_TTF_RenderText_Solid");

    CAMLreturn(Val_SDL_Surface(surf));
}



/* vim: set ts=4 sw=4 et: */
