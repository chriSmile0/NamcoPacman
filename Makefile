all : main

main : 
	mkdir build 2> /dev/null ;\
	cd build ; \
	cmake .. ; \
	make ; \

exec : 
	cd build ; \
	./pacman

clean : 
	-$(RM) -r build