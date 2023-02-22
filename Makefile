all : main

main : clean
	mkdir build 2> /dev/null ;\
	cd build ; \
	cmake .. ; \
	make ; \

exec : main 
	cd build ; \
	./pacman \

clean : 
	-$(RM) -r build