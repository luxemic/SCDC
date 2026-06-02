// HC-SR04 Distance Sensor Starter Code
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a 10-microsecond trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse duration in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Convert to centimeters: sound travels 0.0343 cm/us
  // Divide by 2 because sound travels to object AND back
  float distance = (duration * 0.0343) / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100); // Wait 100ms between readings
}
