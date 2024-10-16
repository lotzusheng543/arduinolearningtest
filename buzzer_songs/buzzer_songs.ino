    /*************以下变量无需修改**********************/
    int note[21][7]={                  /*标准频率对照表*/
    /*A-G大调降音*/  
    {221,248,278,294,330,371,416},             //A大调
    {248,278,294,330,371,416,467},             //B大调
    {131,147,165,175,196,221,248},             //C大调
    {147,165,175,196,221,248,278},             //D大调
    {165,175,196,221,248,278,294},             //E大调
    {175,196,221,248,278,294,330},             //F大调
    {196,221,248,278,294,330,371},             //G大调
    /*A-G大调标准音*/
    {441,495,556,624,661,742,833},
    {495,556,624,661,742,833,935},
    {262,294,330,350,393,441,495},
    {294,330,350,393,441,495,556},
    {330,350,393,441,495,556,624},
    {350,393,441,495,556,624,661},
    {393,441,495,556,624,661,742},
    /*A-G大调升音*/
    {882,990,1112,1178,1322,1484,1665},
    {990,1112,1178,1322,1484,1665,1859},
    {525,589,661,700,786,882,990},
    {589,661,700,786,882,990,1112},
    {661,700,786,882,990,1112,1178},
    {700,786,882,990,1112,1178,1322},
    {786,882,990,1112,1178,1322,1484},
    
    };
    
    /*************以下变量依据实际修改****************/
    int buzzerPin = 13;              /*蜂鸣器引脚位置*/
    int BPM = 400;                  /*一拍的时间*/
    int Scale = 4;                  /*设置大调，A-Z分别对应1-7*/
    float rate = 0.1;               /*发声时间占一拍时间的比率*/
    
    /*****TMD 蜂鸣器唱歌真难听*****/
    //天空之城
    int pitch[] =
    {
    6, 7, 1, 7, 1, 3, 7, 3, 6, 5, 6, 1, 5, 3, 4, 3, 4, 1, 3, 1, 7, 4, 4, 7, 7, 6, 7, 1, 7, 1, 3, 7, 3, 3, 6, 5, 6, 1, 5, 3, 4, 1, 7, 1, 2, 3, 1, 1, 1, 7, 6, 7, 5, 6, 6, 6, 1, 2, 3, 2, 3, 5, 2, 2, 2, 5, 1, 7, 1, 2, 3, 3, 3, 3, 3, 6, 7, 1, 7, 1, 2, 1, 5, 5, 5, 4, 3, 2, 1, 3, 3, 3, 3, 6, 6, 5, 5, 3, 2, 1, 1, 1, 2, 1, 2, 5, 3, 3, 3, 3, 6, 6, 5, 5, 3, 2, 1, 1, 1, 2, 1, 2, 7, 6, 6, 6, 0,
    };
    int rise[] =
    {
    0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
    };
    float mlength[] =
    {
    0.500, 0.500, 1.500, 0.500, 1.000, 1.000, 3.000, 1.000, 0.500, 1.000, 1.000, 1.000, 3.000, 1.000, 1.500, 0.500, 0.500, 1.500, 3.000, 1.000, 1.500, 0.500, 0.500, 1.000, 3.000, 0.500, 0.500, 1.500, 0.500, 1.000, 1.000, 3.000, 0.500, 0.500, 1.500, 0.500, 1.000, 1.000, 3.000, 1.000, 1.000, 0.500, 1.500, 1.000, 1.000, 0.500, 0.500, 2.000, 0.500, 0.500, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 0.500, 0.500, 1.500, 0.500, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.500, 0.500, 1.000, 0.500, 0.500, 1.000, 1.000, 1.000, 1.000, 0.500, 0.500, 1.000, 0.500, 0.500, 1.000, 1.500, 0.500, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.500, 0.500, 1.500, 0.500, 0.500, 0.500, 1.000, 1.000, 1.000, 1.500, 0.500, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.500, 0.500, 1.500, 0.500, 0.500, 0.500, 1.000, 1.000, 1.000, 1.500, 0.500, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000,
    };
    /*两只老虎
    int pitch[] =
    {
    1, 2, 3, 1, 1, 2, 3, 1, 3, 4, 5, 3, 4, 5, 5, 6, 5, 4, 3, 1, 0, 0, 1, 2, 3, 1, 1, 2, 3, 1, 3, 4, 5, 3, 4, 5,
    };
    int rise[] =
    {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    float mlength[] =
    {
    1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 2.000, 1.000, 1.000, 2.000, 0.500, 0.500, 0.500, 0.500, 1.000, 1.000, 1.000, 3.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 2.000, 1.000, 1.000, 2.000,
    };*/
    /*追光者*/
    /*int pitch[] =
    {
    0, 0, 0, 0, 6, 7, 1, 7, 3, 3, 5, 5, 1, 2, 1, 2, 2, 5, 3, 6, 7, 1, 7, 3, 3, 5, 1, 5, 1, 2, 3, 1, 7, 6, 7, 1, 1, 3, 2, 7, 6, 5, 6, 7, 7, 2, 1, 0, 1, 7, 1, 0, 6, 6, 7, 1, 7, 6, 5, 0, 1, 2,
    };
    
    int rise[] =
    {
    1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2,
    };*/
    
    
    
    
    
    void setup() {
      pinMode(buzzerPin,OUTPUT);
      
    }
    
    void loop() {
      int i;
      int Frequency;
      int toneTime,notoneTime;
      
      for(i = 0;i < sizeof(note) / sizeof(int);i++)
      {
        if(pitch[i] != 0)
        {
          Frequency = note[Scale + rise[i] * 7 ][pitch[i]];
          
          toneTime = mlength[i] * BPM * rate;
          notoneTime = mlength[i] * BPM - toneTime;
          
          tone(buzzerPin,Frequency);
          delay(toneTime);
          delay(notoneTime);
          noTone(buzzerPin);
        }
        
        else delay(BPM * mlength[i]);  
      }
      
      delay(10000);
    }



