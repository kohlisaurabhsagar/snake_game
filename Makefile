all: compile link

compile:
   g++ main.o -o sfml-app -L"C:\msys64\SFML-2.6.1\include" -lsfml-graphics -lsfml-window -lsfml-system -DSFML_STATIC  

link:
   g++ main.o -o sfml-app -L"C:\msys64\SFML-2.6.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows g++ main.o -o sfml-app -LC:\\msys64\\SFML-2.6.1\\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
   rm -f main *.o

