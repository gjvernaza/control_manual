

#include "BluetoothSerial.h"

//////// valores de los pines del motor 1 //////////
const int phase_A_M1 = 35;
const int phase_B_m1 = 34;
const int ENA_M1 = 5;
const int IN1_M1 = 18;
const int IN2_M1 = 19;

//////// valores de los pines del motor 2 //////////
const int phase_A_M2 = 33;
const int phase_B_M2 = 32;
const int ENB_M2 = 23;
const int IN3_M2 = 21;
const int IN4_M2 = 22;

//////// valores de los pines del motor 3 //////////
const int phase_A_M3 = 26;
const int phase_B_M3 = 25;
const int ENA_M3 = 15;
const int IN1_M3 = 2;
const int IN2_M3 = 0;

//////// valores de los pines del motor 4 //////////
const int phase_A_M4 = 14;
const int phase_B_M4 = 27;
const int ENB_M4 = 17;
const int IN3_M4 = 4;
const int IN4_M4 = 16;



BluetoothSerial SerialBT;  


void setup()
{
    Serial.begin(115200);
    SerialBT.begin("ESP32test"); 
    pinMode(phase_A_M1, INPUT);
    pinMode(phase_B_m1, INPUT);
    pinMode(phase_A_M2, INPUT);
    pinMode(phase_B_M2, INPUT);
    pinMode(phase_A_M3, INPUT);
    pinMode(phase_B_M3, INPUT);
    pinMode(phase_A_M4, INPUT);
    pinMode(phase_B_M4, INPUT);

    pinMode(ENA_M1, OUTPUT); 
    pinMode(ENB_M2, OUTPUT);
    pinMode(ENA_M3, OUTPUT);
    pinMode(ENB_M4, OUTPUT);

    

    pinMode(IN1_M1, OUTPUT);
    pinMode(IN2_M1, OUTPUT);
    pinMode(IN3_M2, OUTPUT);
    pinMode(IN4_M2, OUTPUT);
    pinMode(IN1_M3, OUTPUT); 
    pinMode(IN2_M3, OUTPUT);
    pinMode(IN3_M4, OUTPUT);
    pinMode(IN4_M4, OUTPUT);

    digitalWrite(IN1_M1, LOW);
    digitalWrite(IN2_M1, LOW); 
    digitalWrite(IN3_M2, LOW);
    digitalWrite(IN4_M2, LOW);
    digitalWrite(IN1_M3, LOW);
    digitalWrite(IN2_M3, LOW);
    digitalWrite(IN3_M4, LOW);
    digitalWrite(IN4_M4, LOW);
    
}




void fordward(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, HIGH);
    digitalWrite(ENB_M2, HIGH);
    digitalWrite(ENA_M3, HIGH);
    digitalWrite(ENB_M4, HIGH);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, LOW);
    digitalWrite(IN2_M1, HIGH);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, LOW);
    digitalWrite(IN4_M2, HIGH);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, LOW);
    digitalWrite(IN2_M3, HIGH);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, LOW);
    digitalWrite(IN4_M4, HIGH);
}

void backward(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, HIGH);
    digitalWrite(ENB_M2, HIGH);
    digitalWrite(ENA_M3, HIGH);
    digitalWrite(ENB_M4, HIGH);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, HIGH);
    digitalWrite(IN2_M1, LOW);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, HIGH);
    digitalWrite(IN4_M2, LOW);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, HIGH);
    digitalWrite(IN2_M3, LOW);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, HIGH);
    digitalWrite(IN4_M4, LOW);
}

void right(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, HIGH);
    digitalWrite(ENB_M2, HIGH);
    digitalWrite(ENA_M3, HIGH);
    digitalWrite(ENB_M4, HIGH);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, HIGH);
    digitalWrite(IN2_M1, LOW);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, LOW);
    digitalWrite(IN4_M2, HIGH);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, HIGH);
    digitalWrite(IN2_M3, LOW);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, LOW);
    digitalWrite(IN4_M4, HIGH);
}

void left(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, HIGH);
    digitalWrite(ENB_M2, HIGH);
    digitalWrite(ENA_M3, HIGH);
    digitalWrite(ENB_M4, HIGH);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, LOW);
    digitalWrite(IN2_M1, HIGH);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, HIGH);
    digitalWrite(IN4_M2, LOW);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, LOW);
    digitalWrite(IN2_M3, HIGH);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, HIGH);
    digitalWrite(IN4_M4, LOW);
}

void sup_right(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, LOW);
    digitalWrite(ENB_M2, HIGH);
    digitalWrite(ENA_M3, LOW);
    digitalWrite(ENB_M4, HIGH);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, LOW);
    digitalWrite(IN2_M1, LOW);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, LOW);
    digitalWrite(IN4_M2, HIGH);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, LOW);
    digitalWrite(IN2_M3, LOW);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, LOW);
    digitalWrite(IN4_M4, HIGH);

}

void sup_left(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, HIGH);
    digitalWrite(ENB_M2, LOW);
    digitalWrite(ENA_M3, HIGH);
    digitalWrite(ENB_M4, LOW);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, LOW);
    digitalWrite(IN2_M1, HIGH);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, LOW);
    digitalWrite(IN4_M2, LOW);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, LOW);
    digitalWrite(IN2_M3, HIGH);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, LOW);
    digitalWrite(IN4_M4, LOW);

}

void inf_right(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, HIGH);
    digitalWrite(ENB_M2, LOW);
    digitalWrite(ENA_M3, HIGH);
    digitalWrite(ENB_M4, LOW);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, HIGH);
    digitalWrite(IN2_M1, LOW);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, LOW);
    digitalWrite(IN4_M2, LOW);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, HIGH);
    digitalWrite(IN2_M3, LOW);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, LOW);
    digitalWrite(IN4_M4, LOW);

}

void inf_left(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, LOW);
    digitalWrite(ENB_M2, HIGH);
    digitalWrite(ENA_M3, LOW);
    digitalWrite(ENB_M4, HIGH);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, LOW);
    digitalWrite(IN2_M1, LOW);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, HIGH);
    digitalWrite(IN4_M2, LOW);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, LOW);
    digitalWrite(IN2_M3, LOW);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, HIGH);
    digitalWrite(IN4_M4, LOW);

}

void rotate_right(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, HIGH);
    digitalWrite(ENB_M2, HIGH);
    digitalWrite(ENA_M3, HIGH);
    digitalWrite(ENB_M4, HIGH);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, HIGH);
    digitalWrite(IN2_M1, LOW);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, LOW);
    digitalWrite(IN4_M2, HIGH);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, LOW);
    digitalWrite(IN2_M3, HIGH);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, HIGH);
    digitalWrite(IN4_M4, LOW);

}

void rotate_left(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, HIGH);
    digitalWrite(ENB_M2, HIGH);
    digitalWrite(ENA_M3, HIGH);
    digitalWrite(ENB_M4, HIGH);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, LOW);
    digitalWrite(IN2_M1, HIGH);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, HIGH);
    digitalWrite(IN4_M2, LOW);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, HIGH);
    digitalWrite(IN2_M3, LOW);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, LOW);
    digitalWrite(IN4_M4, HIGH);

}

void stop(){
    //HABILITAR MOTORES
    digitalWrite(ENA_M1, LOW);
    digitalWrite(ENB_M2, LOW);
    digitalWrite(ENA_M3, LOW);
    digitalWrite(ENB_M4, LOW);
    //SENTIDO MOTOR 1
    digitalWrite(IN1_M1, LOW);
    digitalWrite(IN2_M1, LOW);
    //SENTIDO MOTOR 2
    digitalWrite(IN3_M2, LOW);
    digitalWrite(IN4_M2, LOW);
    //SENTIDO MOTOR 3
    digitalWrite(IN1_M3, LOW);
    digitalWrite(IN2_M3, LOW);
    //SENTIDO MOTOR 4
    digitalWrite(IN3_M4, LOW);
    digitalWrite(IN4_M4, LOW);
}

void loop(){
    if (SerialBT.available()){
        char dataBT = SerialBT.read();
        if(dataBT == '1'){
            fordward();
        }
        else if(dataBT == '2'){
            backward();
        }
        else if(dataBT == '3'){
            right();
        }
        else if(dataBT == '4'){
            left();
        }
        else if(dataBT == '5'){
            sup_right();
        }
        else if(dataBT == '6'){
            sup_left();
        }
        else if(dataBT == '7'){
            inf_right();
        }
        else if(dataBT == '8'){
            inf_left();
        }
        else if(dataBT == '9'){
            rotate_right();
        }
        else if(dataBT == '0'){
            rotate_left();
        }
        else if(dataBT == 's'){
            stop();
        }
    }
    
}

