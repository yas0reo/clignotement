#include <Arduino.h>
#include <Bounce2.h>

#define BROCHE_DEL 3
#define BROCHE_BOUTON 2

Bounce2::Button bouton = Bounce2::Button();

bool etatDel = LOW;

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

    // Une nouvelle pression a-t-elle été détectée ?
    if (bouton.pressed())
    {
        if ( etatDel == 0 ) {
            etatDel = 1;
        } else {
            etatDel = 0;    
        }

        digitalWrite(BROCHE_DEL, etatDel);
    }
}
