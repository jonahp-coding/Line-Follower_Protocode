
// make a class for motor and functions
// Use #define for variables that do not change...

uint8_t input_1_pin = 13;
uint8_t input_2_pin = 12;
uint8_t input_3_pin = 11;
uint8_t input_4_pin = 10;

uint8_t motor_1_pwm_pin = 6;
uint8_t motor_2_pwm_pin = 5;

uint8_t ir_1_pin = 8;
uint8_t ir_2_pin = 7;

bool motor_1_dir = true;
bool motor_2_dir = true;

bool ir_1_state = true;
bool ir_2_state = true;

uint8_t base_speed = 127;

uint16_t current_millis = millis();

void setup() {

  Serial.begin(115200);

  // ...
  pinMode(input_1_pin, OUTPUT);
  pinMode(input_2_pin, OUTPUT);
  pinMode(input_3_pin, OUTPUT);
  pinMode(input_4_pin, OUTPUT);

  pinMode(motor_1_pwm_pin, OUTPUT);
  pinMode(motor_2_pwm_pin, OUTPUT);

  pinMode(ir_1_pin, INPUT);
  pinMode(ir_2_pin, INPUT);

  // Intial settings
  motor_1_set_pwm(base_speed);
  motor_2_set_pwm(base_speed);
  
  motor_1_reverse_dir(motor_1_dir);
  motor_2_reverse_dir(motor_2_dir);
}

void loop() {

  ir_1_state = digitalRead(ir_1_pin);
  ir_2_state = digitalRead(ir_2_pin);

  if (ir_1_state == false) {
    motor_1_set_pwm(base_speed);
    motor_2_set_pwm(0);
  }
  
  if (ir_2_state == false) {
    motor_1_set_pwm(0);
    motor_2_set_pwm(base_speed);
  }

  Serial.print("ir_1_state: ");
  Serial.println(ir_1_state);
  Serial.print("ir_2_state: ");
  Serial.println(ir_2_state);

  Serial.println("-----------------------------");

  delay(10);

}

void motor_1_reverse_dir(bool reverse) {
  if (reverse) {
    digitalWrite(input_1_pin, LOW);
    digitalWrite(input_2_pin, HIGH);
  } else {
    digitalWrite(input_1_pin, HIGH);
    digitalWrite(input_2_pin, LOW);
  }
}

void motor_2_reverse_dir(bool reverse) {
  if (reverse) {
    digitalWrite(input_3_pin, LOW);
    digitalWrite(input_4_pin, HIGH);
  } else {
    digitalWrite(input_3_pin, HIGH);
    digitalWrite(input_4_pin, LOW);
  }
}

void motor_1_set_pwm(uint8_t val) {
  analogWrite(motor_1_pwm_pin, val);
}

void motor_2_set_pwm(uint8_t val) {
  analogWrite(motor_2_pwm_pin, val);
}
