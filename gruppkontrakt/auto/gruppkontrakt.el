(TeX-add-style-hook
 "gruppkontrakt"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8")))
   (TeX-run-style-hooks
    "latex2e"
    "mall"
    "mall10"
    "inputenc")
   (TeX-add-symbols
    "version")
   (LaTeX-add-labels
    "prereq"))
 :latex)

