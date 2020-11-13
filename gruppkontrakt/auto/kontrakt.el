(TeX-add-style-hook
 "kontrakt"
 (lambda ()
   (TeX-run-style-hooks
    "latex2e"
    "mall"
    "mall10")
   (TeX-add-symbols
    "version")
   (LaTeX-add-labels
    "prereq"))
 :latex)

