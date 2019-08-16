# 테라 클래식 소탕 매크로 설명서
> Python 모듈로 간단하게 구현.


 * 테라 클래식이라는 모바일게임에서 "소탕 퀘스트"를 자동으로 진행하고 싶어서 매크로를 제작  
 * 커스텀 하려면 Python 3.7.4, pyautogui 설치가 필요 (다른 버전은 테스트 해 보지 않음)     
 

 ## 1. 시작 전 에뮬레이터 세팅 
 
 
 * 사용 에뮬레이터 :
 
     * LDPlayer
 
 * 해상도 :

     * 1280 x 720 (dpi 240)
     * 다른 해상도는 아직 미구현
  
  

 ## 2. .exe 파일을 실행 시키는 방법  

 
 ![화면2](https://user-images.githubusercontent.com/46941349/63182647-ff709200-c08d-11e9-82a6-7755fc70dc25.PNG)
 1. 소탕 환경, 가방 비우기를 설정한다.
 2. 소탕 버튼이 보이게 켜두고 '시작' 버튼을 누른다.  
 
 ### * 항상 윈도우 최상위에 LDPlay가 실행되고 있어야 동작한다. 따라서 자는시간에 이용한다.
 
 
 ## 3. Python 언어를 사용해서 구동 및 커스텀을 하기위한 개발환경 설명  
 ### Python 설치하기  
 Python 설치는 공식 [홈페이지](https://www.python.org/) 참고  
 ### pyautogui 설치하기  
```sh
pip install pyautigui
```
 ### tkinter 설치하기  
 간혹 Python은 설치되어있는데 tkinter가 설치되어있지 않은 경우가 있다.  
 ```sh
 pip install tkinter
 ```
 ### 구동 및 커스텀 하기
 [요기](https://github.com/Sungmin-Joo/Codes_for_Beginners/tree/master/Python) 혹은 킹갓 Google을 이용하여 Python을 공부해서 커스텀을 하면 된다.
 
 ## 버전
 * v1.0 - 엄청 간단하게 버튼을 찾아서 눌러준다. (버전이라 표기하기도 민망하다)
 
 ## 정보

 주성민(Joo Sung Min) – big-joo_dev@naver.com  
 버그가 있다면 제보를 부탁 드립니다.
