#define ledPin 13  //LED 디지털 핀 13번에 연결
#define LINE_DETECT_WHITE  1


int linesensor_data[5] = {0,0,0,0,0};  //읽은 값을 저장할 변수
int linesensor_pin[5] = {2,3,4,5,6};   //int형 배열

int read_digital_line_sensor(void)
{
  int i;
  int sum = 0;
  for(i=0;i<5;i++)
  {
    if(LINE_DETECT_WHITE == 0)
    {
      linesensor_data[i] = 1 - digitalRead(linesensor_pin[i]);
    }
    else
    {
      linesensor_data[i] = digitalRead(linesensor_pin[i]);
    }
    sum += linesensor_data[i];
  }
  return sum;
}

void setup() {
  int i;
  pinMode(ledPin, OUTPUT);    // 13번 핀 출력으로 설정

  for(i=0;i<5;i++)
  {
      pinMode(linesensor_pin[i], INPUT);      // 라인 센선 핀 입력으로 설정
  }
  
  Serial.begin(9600);
}

void loop() {
  int i;
  int sum = 0;
  sum = read_digital_line_sensor();  // 함수 실행

  Serial.print("Input data = ");
  for(i=0;i<5;i++)
  {
    Serial.print(linesensor_data[i]);
    Serial.print(" ");
  }
  Serial.print(sum);  //sum 값 출력
  Serial.println(" ");  //줄 바꾸기
}
