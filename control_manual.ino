
#include <WiFi.h>


const char *ssid = "ServerESP32";
const char *password = "1234567890";
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



/////////////////////////// RECEPCIÓN WIFI //////////////////
String inputString = "";
bool stringComplete = false;
const char separator = ',';
const int dataLength = 3;
int data[dataLength];
int outValue = 0;

int value1, value2, value3, out_value;

WiFiServer server(80);



void setup()
{
    Serial.begin(115200);
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

    

    WiFi.softAP(ssid, password);
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());
    server.begin();
}



int get_data(String request){
    for(int i= 0; i<dataLength; i++){
        int pos = request.indexOf(separator);       
        data[i] = request.substring(0, pos).toInt();
        request = request.substring(pos+1);
    }
    value1 = data[0]; 
    value2 = data[1];
    value3 = data[2];
    outValue = value1;
    

    return outValue;
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
    WiFiClient client = server.available();
    if (client)
    {
        while (client.connected())
        {

            if (client.available())
            {
                
                String request = client.readStringUntil('\n');
                //if(request.length() > 0){
                //    request = request.substring(request.length()-1);
                //}
                Serial.println(request);
                out_value = get_data(request);
                if(out_value == 1){
                    // M1, M2, M3, M4 horario
                    
                    fordward();
                    Serial.println("Ok");
                    //client.stop();
                    client.flush();
                } 
                else if(out_value == 2){
                    // M1, M2, M3, M4 antihorario                    
                    backward();
                    //client.stop();
                }
                else if (out_value == 3){
                    // M2, M4 horario, M1, M3 antihorario
                    
                    right();
                    //client.stop();
                }
                else if (out_value == 4){
                    // M2, M4 antihorario, M1, M3 horario
                    left();
                    //client.stop();
                }
                else if (out_value == 5){
                    // M1, M4 horario, M2, M3 antihorario
                    sup_right();
                    //client.stop();
                }
                
                else if (out_value == 6){
                    // M1, M4 antihorario, M2, M3 horario
                    sup_left();
                    //client.stop();
                }
                else if (out_value == 7){
                    // M2, M3 horario, M1, M4 antihorario
                    inf_right();
                    //client.stop();
                }
                else if (out_value == 8){
                    // M2, M3 antihorario, M1, M4 horario
                    inf_left();
                    //client.stop();
                }
                else if (out_value == 9){
                    // M1, M4 horaio, M2, M3 antihorario
                    rotate_right();
                    //client.stop();
                }
                else if (out_value == 10){
                    // M1, M2, M3, M4 antihorario
                    rotate_left();
                    //client.stop();
                }
                
                else {
                    stop();
                    
                }
                
            }
            
        }
        client.stop();
        Serial.println("Client Disconnected.");
    }
    
}