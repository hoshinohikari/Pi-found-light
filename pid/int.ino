const int buttonPin = A3;

int black1;

void init_i()
{
  pinMode(buttonPin, INPUT);
}

int black_1()
{
  black1 = analogRead(buttonPin);
  return black1;
}

