all:
	$(MAKE) -C bme/src
	$(MAKE) -C src

clean: 
	$(MAKE) clean -C bme/src
	$(MAKE) clean -C src
	-rm -f *.html
	-rm -f *.data
	-rm -f *.js