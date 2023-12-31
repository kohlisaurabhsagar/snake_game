#include<SFML/Graphics.hpp>
#include<iostream>
#include<ctime>
using namespace sf;

struct snake
{int x,y;} s[100];

struct fod
{int x,y;} f;

int num = 4;
int dir ;

void snake(){
    for (int i = num; i > 0; i--)
        {s[i].x =s[i-1].x;s[i].y = s[i-1].y;}

    if (dir == 0) s[0].y += 1;
    if (dir == 1) s[0].y -= 1;
    if (dir == 2) s[0].x += 1;
    if (dir == 3) s[0].x -= 1;
   
    for (int i = num; i > 0; i--)
    if(s[0].x == s[i].x && s[0].y == s[i].y)num = 1;

    if (s[0].x < 0) s[0].x = 30; if (s[0].x > 30) s[0].x = 0;
    if (s[0].y < 0) s[0].y = 20; if (s[0].y > 20) s[0].y = 0;

    if(s[0].x == f.x && s[0].y == f.y){num++; f.x = rand() % 30; f.y = rand() % 20;}

}

int main(){

    RenderWindow window(VideoMode(30 * 16, 20 * 16), "snake turorial");

    Texture t1,t2,t3;
        t1.loadFromFile("imageserterte/white.png");
        t2.loadFromFile("imageserterte/red.png"  );
        t3.loadFromFile("imageserterte/green.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);
    Clock clock;

    f.x = 5;
    f.y = 5;

    float timer = 0, delay = 0.1;

    while(window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        Event e;

        while (window.pollEvent(e))
            if(e.type == Event::Closed)
            window.close();


    if (Keyboard::isKeyPressed(Keyboard::Up   )) dir = 1;
    if (Keyboard::isKeyPressed(Keyboard::Down )) dir = 0;
    if (Keyboard::isKeyPressed(Keyboard::Right)) dir = 2;
    if (Keyboard::isKeyPressed(Keyboard::Left )) dir = 3;

    if (timer > delay) {timer = 0; snake();}

    for (int i = 0; i < 30; i++)
        for (int j = 0 ; j < 20 ; j++)
            {sprite1.setPosition(i*16, j*16); window.draw(sprite1);}

    for (int i = 0; i < num; i++)
        {sprite2.setPosition(s[i].x * 16, s[i].y * 16); window.draw(sprite2);}

    {sprite3.setPosition(f.x * 16, f.y * 16); window.draw(sprite3);}

    window.display();

    }

}



