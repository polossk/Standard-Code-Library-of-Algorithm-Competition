TEX      = xelatex
MAIN     = scloac

target: close wipe clean tex open

tex: $(MAIN).tex
	$(TEX) $<
	$(TEX) $<

open: $(MAIN).pdf
	cmd /c start $(MAIN).pdf

close:
	cmd /c taskkill /im Acrobat.exe /t /f || echo not find

clean:
	del -f *.aux *.bbl *.blg *.log *.out *.gz *.toc *.thm

wipe:
	del -f $(MAIN).pdf

.PHONY: clean