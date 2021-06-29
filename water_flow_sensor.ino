
volatile int flow_frequency; 
unsigned int l_hour; 
unsigned char flowsensor = 2;
unsigned long currentTime;
unsigned long cloopTime;
void flow ()
{
   flow_frequency++;
}
void setup()
{
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH);
   Serial.begin(9600);
   attachInterrupt(0, flow, RISING);
   sei(); // Enable interrupts
   currentTime = millis();
   cloopTime = currentTime;
}
void loop ()
{
   currentTime = millis();
   if(currentTime >= (cloopTime + 1000))
   {
      cloopTime = currentTime;
      l_hour = (flow_frequency * 60 / 7.5); 
      flow_frequency = 0; 
      Serial.print(l_hour, DEC); 
      Serial.println(" L/hour");
   }
}
