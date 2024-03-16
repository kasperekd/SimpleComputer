.PHONY: all clean

all:
	@$(MAKE) -C mySimpleComputer
	@$(MAKE) -C myBigChars
	@$(MAKE) -C myTerm
	@$(MAKE) -C console
	
clean:
	@$(MAKE) -C mySimpleComputer clean
	@$(MAKE) -C myBigChars clean
	@$(MAKE) -C myTerm clean
	@$(MAKE) -C console clean