//уводзяцца канстанты, якія задаюць выкарыстоўваемыя нумары вывадаў платы, інтэрвалы часу ў мілісекундах і лагічныя зменныя
const int IN1 = 2; //Падключаем IN1 драйвера з вывадам 2
const int IN2 = 3; //Падключаем IN2 драйвера з вывадам 3
const int IN3 = 4; //Падключаем IN3 драйвера з вывадам 4
const int IN4 = 5; //Падключаем IN4 драйвера з вывадам 5
const int ENA = 6; //Падключаем кіруючы ўваход матора В да вывада 6
const int ENB = 7; //Падключаем кіруючы ўваход матора А да вывада 7
const int buttonDecrease = 8; //Падключаем кнопку памяншэння хуткасці да вывада 8
const int buttonIncrease = 9; //Падключаем кнопку павелічэння хуткасці да вывада 9

int stepDelay = 4; //Час затрымкі паміж крокамі
unsigned long lastPressTime = 0; //Час апошняга націску 
const int crucialTime = 300; //Час супраць дрэбезгу
bool dir = 0; //Зменная для накірунку


void setup() {
  //настройка рэжыма піноў для драйвера ў рэжым выхаду
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(buttonIncrease, INPUT_PULLUP); //Для кнопак пакдлючаем прыём з падцягваючымся рэзістарам
  pinMode(buttonDecrease, INPUT_PULLUP); 
  Serial.begin(9600);
  digitalWrite(ENA, HIGH); //Уключэнне працы піноў матора А (катушкі 1)
  digitalWrite(ENB, HIGH); //Уключэнне працы піноў матора В (катушкі 1)
}

void loop() {
    unsigned long currentTime = millis(); //Таймер

  //Настройка накірунку кручэння рухавіка з дапамогай адначасовага націску кнопак
    if(digitalRead(buttonIncrease) == LOW && digitalRead(buttonDecrease) == LOW && (currentTime - lastPressTime > crucialTime)) {
      dir = !dir; //Сама змена накірунку
      lastPressTime = currentTime; //Фіксуем час націску кнопак
    }

    //Настройка памяншэння хуткасці пры націску кнопкі
    if (digitalRead(buttonDecrease) == LOW  && (currentTime - lastPressTime > crucialTime)) {
     stepDelay += 1; //Павелічэнне затрымкі паміж крокамі
      lastPressTime = currentTime; //Фіксуем час націску кнопак
    }

    //Настройка павелічэння хуткасці пры націску іншай кнопкі
    if (digitalRead(buttonIncrease) == LOW && (currentTime - lastPressTime > crucialTime)) {
      if (stepDelay > 2) stepDelay -= 1; //Памяншэнне затрымкі паміж крокамі
    lastPressTime = currentTime; //Фіксуем час націску кнопак
  }

  //Хацелася б адзначыць, што далей пры пераходзе паміж двума крокавымі камутацыямі адбываецца 1 крок
  //Задаццё працы для кручэння ў адным накірунку
  if(!dir) {
    //1-ая крокавая камутацыя
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(stepDelay); //Затрымка паміж крокамі
     //2-ая крокавая камутацыя
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(stepDelay); //Затрымка паміж крокамі
     //3-яя крокавая камутацыя
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(stepDelay); //Затрымка паміж крокамі
    //4-ая крокавая камутацыя
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(stepDelay); //Затрымка паміж крокамі
  }

  //Задаццё працы для кручэння ў адваротным накірунку
  if (dir) {
    //1-ая крокавая камутацыя
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(stepDelay); //Затрымка паміж крокамі
    //2-ая крокавая камутацыя
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(stepDelay); //Затрымка паміж крокамі
    //3-яя крокавая камутацыя
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(stepDelay); //Затрымка паміж крокамі
    //4-ая крокавая камутацыя
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(stepDelay); //Затрымка паміж крокамі
  }
}
