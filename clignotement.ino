#include <Arduino.h>
#include <Chrono.h>
#include <Bounce2.h>

#define BROCHE_DEL 3
#define BROCHE_BOUTON 2

#define INTERVALLE 500

Bounce2::Button bouton = Bounce2::Button();
Chrono minuterieDel;

bool etatDel = LOW;
bool clignotementActif = false;

void setup()
{
    // Configuration de la DEL
    pinMode(BROCHE_DEL, OUTPUT);
    digitalWrite(BROCHE_DEL, etatDel);

    // Configuration du bouton
    bouton.attach(BROCHE_BOUTON, INPUT_PULLUP);
    bouton.setPressedState(LOW);
}

void loop()
{
    // Mise à jour du bouton
    bouton.update();

    // Gestion de l'événement de pression
    if (bouton.pressed())
    {
        if (clignotementActif) {
            clignotementActif = false;
        } else {
             clignotementActif = true;
        }
    }

    // Gestion indépendante du clignotement
    if (clignotementActif) {
        if ( minuterieDel.hasPassed(INTERVALLE)) 
        {
            minuterieDel.restart();

            if ( etatDel == 0 ) {
                etatDel = 1;
            } else {
                etatDel = 0;    
            }
            
        }
    } 

    digitalWrite(BROCHE_DEL, etatDel);
}
