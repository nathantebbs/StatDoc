exec = statdoc.out
name = statdoc
sources = $(wildcard *.c)
obj = $(sources:.c=.o)
flags = -g -Wall

$(exec): $(obj)
	gcc $(obj) $(flags) -o $(exec)
	
%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@
	
install: $(exec)
	cp ./$(exec) /usr/bin/$(name)
	@ echo -e "\033[0;32mInstall Complete!\033[0m"
	@ echo -e "\033[0;35mRun the statdoc command to try it out!\033[0m"

uninstall:
	-rm /usr/bin/$(name)
	@ echo -e "\033[0;31mUninstall Complete!\033[0m"

clean:
	rm -rf $(exec)
	rm -rf *.o
