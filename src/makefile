all :  filtertool

libraries: libfiltertool.a libfiltertool.so 

Image.o : Image.h Image.C
	c++ -c Image.C -fPIC

ImagePGM.o : ImagePGM.h ImagePGM.C
	c++ -c ImagePGM.C -fPIC

ImagePPM.o : ImagePPM.h ImagePPM.C
	c++ -c ImagePPM.C -fPIC

libfiltertool.a : Image.o ImagePGM.o ImagePPM.o
	ar cr libfiltertool.a Image.o ImagePGM.o ImagePPM.o

libfiltertool.so :  Image.o ImagePGM.o ImagePPM.o
	c++ -shared -o libfiltertool.so  Image.o ImagePGM.o ImagePPM.o

filtertool.o :   filtertool.C ImagePPM.h
	c++ -c filtertool.C 

filtertool : filtertool.o libfiltertool.so
	 c++ -fPIC filtertool.o -L. -lfiltertool -o filtertool 

clean :
	rm -f *.o  filtertool *~
