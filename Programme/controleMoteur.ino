#include "moteur.h"

char* name = "Controle Moteur";
char* serverID = (char*)calloc(140,sizeof(char));
Moteur<std::string>* moteur = new Moteur<std::string>(NULL,NULL);

void setup() {

    Serial.begin(9600);           // set up Serial library at 9600 bps

    //motors
    moteur->addMotor(A0,D0,0);
    moteur->addMotor(A1,D1,1);

    Spark.variable("name",name,STRING);
    Spark.variable("serverID",serverID,STRING);

    Spark.function("connect", &ClientTCP::connectToMyServer,moteur->getClient());
}

void loop() {
    moteur->commServeur();
}
