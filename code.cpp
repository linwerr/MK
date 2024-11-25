const int led1 = 11; // Пин для первого светодиода
const int led2 = 10; // Пин для второго светодиода
const int button = 3; // Пин для кнопки

bool isFlashing = false; // Флаг состояния мигалки
bool buttonState = false; // Текущее состояние кнопки
bool lastButtonState = false; // Предыдущее состояние кнопки

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);

  // Проверяем нажатие кнопки (переключение)
  if (buttonState && !lastButtonState) {
    isFlashing = !isFlashing; // Переключаем состояние мигалки
  }
  lastButtonState = buttonState;

  if (isFlashing) {
    // Включаем попеременное мигание светодиодов
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(150); // Задержка
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(150);
  } else {
    // Выключаем светодиоды
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}
