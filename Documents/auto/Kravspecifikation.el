(TeX-add-style-hook
 "Kravspecifikation"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("babel" "swedish")))
   (TeX-run-style-hooks
    "latex2e"
    "TDP005mall"
    "TDP005mall10"
    "inputenc"
    "babel"
    "tabularx")
   (TeX-add-symbols
    "version")
   (LaTeX-add-labels
    "tab:1"
    "fig:1"
    "tab:2"
    "fig:2"
    "tab:3"
    "fig:3"
    "tab:4"
    "fig:4"))
 :latex)

