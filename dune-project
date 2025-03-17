(lang dune 3.15)

(name caml-sdl2-ttf)
(version 1.0)

(generate_opam_files true)

(source
 (github ssbx/caml-sdl2-ttf))

(authors "Seb")

(maintainers "Seb")

(license "BSD Zero Clause License")

(documentation https://github.com/ssbx/caml-sdl2-ttf)

(use_standard_c_and_cxx_flags true)

(formatting (enabled_for ocaml))

(package
 (name caml-sdl2-ttf)
 (synopsis "Bindings to the SDL2 ttf library")
 (description "Bindings to the SDL2 ttf library")
 (depends
   ocaml
   dune
   caml-sdl2
   (unix :with-test))
 (tags
  (topics bindings graphics image loader)))

; See the complete stanza docs at https://dune.readthedocs.io/en/stable/dune-files.html#dune-project
