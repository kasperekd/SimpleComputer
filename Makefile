.PHONY: all clean

all:
	@$(MAKE) -C mySimpleComputer
	@$(MAKE) -C myCache
	@$(MAKE) -C myBigChars
	@$(MAKE) -C myTerm
	@$(MAKE) -C myReadkey
	@$(MAKE) -C console
	@$(MAKE) -C translators
	
clean:
	@$(MAKE) -C mySimpleComputer clean
	@$(MAKE) -C myCache clean
	@$(MAKE) -C myBigChars clean
	@$(MAKE) -C myTerm clean
	@$(MAKE) -C myReadkey clean
	@$(MAKE) -C console clean
	@$(MAKE) -C translators clean