#ifndef _CAML_TTF_STUB_H_
#define _CAML_TTF_STUB_H_

static value Val_TTF_Font(TTF_Font * p)
{
	return caml_copy_nativeint((intnat) p);
}

static TTF_Font * TTF_Font_val(value v)
{
    return (TTF_Font *) Nativeint_val(v);
}

#endif /* _CAML_TTF_STUB_H_ */

/* vim: set ts=4 sw=4 et: */
