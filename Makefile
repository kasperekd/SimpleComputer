.PHONY: all clean

all:
	@$(MAKE) -C mySimpleComputer
	@$(MAKE) -C console
	
clean:
	@$(MAKE) -C mySimpleComputer clean
	@$(MAKE) -C console clean