.PHONY: all clean

all:
	@$(MAKE) -C mySimpleComputer
	@$(MAKE) -C myTerm
	@$(MAKE) -C console
	
clean:
	@$(MAKE) -C mySimpleComputer clean
	@$(MAKE) -C myTerm clean
	@$(MAKE) -C console clean