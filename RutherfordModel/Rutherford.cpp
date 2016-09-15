

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <iomanip>

const float coloumbConstant = 8.987551787 * pow(10,9);
const float electronCharge = 1.60217662 * pow(10,-19);

class electron{
public:
    
    long double xAcceleration = 0;
    long double yAcceleration = 0;
    long double radius = 0;
    
    
    long double verticalDistance = 0;
    long double horizontalDistance = 0;
    long double force = 0;
    
    long double xMove = 0;
    long double yMove = 0;
    
    long double yVelocity = 0;
    long double  xVelocity = 0;
    
    float mass = 1;
    
    sf::CircleShape body;
    
    
    
    
    electron(long double xPos, long double yPos){
        body.setRadius(5);
        body.setFillColor(sf::Color::Red);
        body.setPosition(xPos, yPos);
        
        
        
        
    }
};


int main(int, char const**)
{
    
    sf::RenderWindow window(sf::VideoMode(1400, 900), "SFML window");
    window.setFramerateLimit(90);
    
    
    
    
    sf::CircleShape proton(5);
    proton.setPosition(700, 450);
    proton.setFillColor(sf::Color::Green);
    proton.setOrigin(5,5);
    
    sf::CircleShape proton2(5);
    proton2.setPosition(700, 450);
    proton2.setFillColor(sf::Color::Green);
    proton2.setOrigin(5,5);
    
    sf::CircleShape proton3(5);
    proton3.setPosition(700, 450);
    proton3.setFillColor(sf::Color::Green);
    proton3.setOrigin(5,5);
    
    
    
    /*
    
    sf::CircleShape electron(5);
    electron.setPosition(700, 550);
    electron.setFillColor(sf::Color::Red);
    electron.setOrigin(5, 5);
    
    
    
    long double radius = 0;
    
    
    long double verticalDistance = 0;
    long double horizontalDistance = 0;
    long double force = 0;
    
    long double xMove = 0;
    long double yMove = 0;
    
    long double momentum = 0;
    long double mass = 1;
    long double xAcceleration;
    long double yAcceleration;
    long double yVelocity = 0;*/
    
    

    //float xVelocity = pow(radius, -0.5);
    
    // try setting xVelocity = 35
    
    long double time;
    time = 1.f/600.f;
    
    
    std::vector <sf::CircleShape> protonList;
    std::vector <electron::electron *> electronList;
   
    
   
    
    protonList.push_back(proton);
    protonList.push_back(proton2);
    //protonList.push_back(proton3);
    
    long double Z = protonList.size();
    
    electron electron(700,650);
    
    electron.radius = pow(pow((electron.body.getPosition().x - proton.getPosition().x),2) + pow(electron.body.getPosition().y - proton.getPosition().y,2),0.5);
    electron.horizontalDistance =  -1 * (electron.body.getPosition().x - proton.getPosition().x);
    electron.verticalDistance =  -1 * (electron.body.getPosition().y - proton.getPosition().y);
    
    
    electron::electron electron2(700,450 - 200);
    
    electron2.radius = pow(pow((electron2.body.getPosition().x - proton.getPosition().x),2) + pow(electron2.body.getPosition().y - proton.getPosition().y,2),0.5);
    electron2.horizontalDistance =  -1 * (electron2.body.getPosition().x - proton.getPosition().x);
    electron2.verticalDistance =  -1 * (electron2.body.getPosition().y - proton.getPosition().y);
    
   /* electron2.xVelocity =    pow((Z *  coloumbConstant * pow(electronCharge,2) * pow(10,36))/electron2.radius, 0.5) * cos(30*3.14/180);
    
    electron2.yVelocity =    pow((Z *  coloumbConstant * pow(electronCharge,2) * pow(10,36))/electron2.radius, 0.5) * sin(30*3.14/180);
    
    electron::electron electron3(700 - 200 * sin(60*3.14/180),250 + 200 * cos(60*3.14/180));
    
    electron3.radius = pow(pow((electron2.body.getPosition().x - proton.getPosition().x),2) + pow(electron2.body.getPosition().y - proton.getPosition().y,2),0.5);
    electron3.horizontalDistance =  -1 * (electron2.body.getPosition().x - proton.getPosition().x);
    electron3.verticalDistance =  -1 * (electron2.body.getPosition().y - proton.getPosition().y);
    
    electron3.xVelocity =    pow((Z *  coloumbConstant * pow(electronCharge,2) * pow(10,36))/electron3.radius, 0.5) * cos(30*3.14/180);
    
    electron3.yVelocity =    -pow((Z *  coloumbConstant * pow(electronCharge,2) * pow(10,36))/electron3.radius, 0.5) * sin(30*3.14/180);*/
    
    //float xVelocity = pow(pow(10,6)/radius, 0.5);
    
    /// force =  (coloumbConstant * pow(electronCharge,2) *  pow(10,34))/pow(radius,2);
    electron.xVelocity = -1 * pow((Z * coloumbConstant * pow(electronCharge,2) * pow(10,36))/electron.radius, 0.5);
    electron2.xVelocity = 1 * pow((Z * coloumbConstant * pow(electronCharge,2) * pow(10,36))/electron.radius, 0.5);
    
  
    bool flag = 0;
    
   
    
    electronList.push_back(&electron);
    electronList.push_back(&electron2);
   // electronList.push_back(&electron3);
    
    window.clear(sf::Color::White);
     window.clear(sf::Color::White);
    
    
    
    
    float xKeyForce = 0;
    float yKeyForce = 0;
   
    while (window.isOpen())
    {
        flag = 0;
        xKeyForce = 0;
         yKeyForce = 0;
       
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed) {
                window.close();
            }

           
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D){
                xKeyForce = 1;
                
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A){
                xKeyForce = -1;
                
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W){
                yKeyForce = -1;
                
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S){
                yKeyForce = 1;
                
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T){
                window.clear(sf::Color::White);
            
                
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I){
                electronList.clear();
                
                
            }
        
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if(flag ==0){
                    electronList.push_back(new electron::electron(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
                        flag = 1;
                    if(electronList.size() > 0){
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                        electronList[electronList.size()-1]->xVelocity = 900;
                    
                    }
                    
                    }
                    
                    
                    
                        
                        
                }
            }
        }
        
         xKeyForce = 0;
         yKeyForce = 0;
        
        for(int a = 0; a < electronList.size(); a++){
        
            electronList[a]->xAcceleration = 0;
        
            electronList[a]->yAcceleration = 0;
            
            
            
            
            
        
        
        for(int i = 0; i < protonList.size(); i++){
        
            electronList[a]->radius = pow(pow((electronList[a]->body.getPosition().x - protonList[i].getPosition().x),2) + pow(electronList[a]->body.getPosition().y - protonList[i].getPosition().y,2),0.5);
            
            electronList[a]->force =  (coloumbConstant * (pow(electronCharge,2)) * pow(10,36))/pow(electronList[a]->radius,2);
            
            
            electronList[a]->horizontalDistance =  -1 * (electronList[a]->body.getPosition().x - protonList[i].getPosition().x);
            electronList[a]->verticalDistance =  -1 * (electronList[a]->body.getPosition().y - protonList[i].getPosition().y);
            
             electronList[a]->xAcceleration +=   (electronList[a]->force * (electronList[a]->horizontalDistance / electronList[a]->radius))/ electronList[a]->mass;
            electronList[a]->yAcceleration +=  (electronList[a]->force * (electronList[a]->verticalDistance / electronList[a]->radius))/electronList[a]->mass;
            
            
            
            
        
        }
            
            
        for(int c = 0; c < electronList.size(); c++){
                if(c != a){
                
                electronList[a]->radius = pow(pow((electronList[a]->body.getPosition().x - electronList[c]->body.getPosition().x),2) + pow(electronList[a]->body.getPosition().y - electronList[c]->body.getPosition().y,2),0.5);
                
                electronList[a]->force = -1 *  (coloumbConstant * (pow(electronCharge,2)) * pow(10,36))/pow(electronList[a]->radius,2);
                
                
                electronList[a]->horizontalDistance =  -1 * (electronList[a]->body.getPosition().x - electronList[c]->body.getPosition().x);
                electronList[a]->verticalDistance =  -1 * (electronList[a]->body.getPosition().y - electronList[c]->body.getPosition().y);
                
                electronList[a]->xAcceleration +=   (electronList[a]->force * (electronList[a]->horizontalDistance / electronList[a]->radius))/ electronList[a]->mass;
                electronList[a]->yAcceleration +=  (electronList[a]->force * (electronList[a]->verticalDistance / electronList[a]->radius))/electronList[a]->mass;
                }
                
                
        }
        
           
        
        
        electronList[a]->xMove = pow(time,2) * electronList[a]->xAcceleration * 0.5 + electronList[a]->xVelocity * (time);
        electronList[a]->yMove = pow(time,2) * electronList[a] -> yAcceleration * 0.5 + electronList[a]->yVelocity * (time);
        
        
        
        
        
        electronList[a]-> xVelocity = electronList[a]->xAcceleration * time + electronList[a]->xVelocity;
        electronList[a]->yVelocity = electronList[a]->yAcceleration * time + electronList[a]->yVelocity;
            
           
          
        
        
      
        
        electronList[a]->body.move(electronList[a]->xMove, electronList[a]->yMove);
  

        
        
        
        
        for(int i = 0; i < protonList.size(); i++){
        if(electronList[a]->body.getGlobalBounds().intersects(protonList[i].getGlobalBounds())){
            electronList[a]->body.setFillColor(sf::Color(0,0,0,0));
        }
        }
        
        }
        
        
       // std::cout << electronList.size() << std::endl;
        
        
        window.clear(sf::Color::White);
        
        

        for(int i = 0; i < protonList.size(); i++){
        window.draw(protonList[i]);
        }
        
         for(int a = 0; a < electronList.size(); a++){
        
        
             window.draw(electronList[a]->body);
         
         }

       
        window.display();
    }
    
    

    return EXIT_SUCCESS;
}
