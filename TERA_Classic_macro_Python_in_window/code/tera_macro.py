import pyautogui
import tkinter
from tkinter import messagebox
import time
import threading

#전역변수 설정
operating=0
mac=[]
point_a=None
point_b=None
point_c=None

#------------------------- tkinter의 디자인. --------------------
window=tkinter.Tk()
window.title("TERA_Classic")
window.geometry("+950+500")
#center(window)
window.resizable(False, False)
global text1, button1


first_f = tkinter.Frame(window)
text1=tkinter.Label(first_f,text = '좌측 상단 좌표 : ', width=20, height=2)
text1.grid(row=0,column=0)
text2=tkinter.Label(first_f,text = '\'q\' 누르고 좌표 설정', width=20, height=2)
text2.grid(row=0,column=1)
Label1=tkinter.Label(first_f,text='<= q', width=13, height = 2)
Label1.grid(row=0,column=2)
first_f.pack()

first_s = tkinter.Frame(window)
text3=tkinter.Label(first_s,text = '우측 하단 좌표 : ', width=20, height=2)
text3.grid(row=0,column=0)
text4=tkinter.Label(first_s,text = '\'w\' 누르고 좌표 설정', width=20, height=2)
text4.grid(row=0,column=1)
Label2=tkinter.Label(first_s,text='<= w', width=13, height = 2)
Label2.grid(row=0,column=2)
first_s.pack()


first_t = tkinter.Frame(window)
text5=tkinter.Label(first_t,text = '버튼 클릭 좌표 : ', width=20, height=2)
text5.grid(row=0,column=0)
text6=tkinter.Label(first_t,text = '\'e\' 누르고 좌표 설정', width=20, height=2)
text6.grid(row=0,column=1)
Label3=tkinter.Label(first_t,text='<= e', width=13, height = 2)
Label3.grid(row=0,column=2)
first_t.pack()

#------------------------- 여기까지 tkinter의 디자인. --------------------


#매크로 시작 전 분석을 위한 사진 데이터 세팅
def set_macro():
    global mac
    if point_a == None or point_b == None or point_c == None:
        messagebox.showinfo("오류","먼저 좌표를 설정해주기!")
    else:
        mac=[]
        for _ in range(30):
            mac.append(pyautogui.screenshot(region=(point_a[0], point_a[1],
                                            point_b[0]-point_a[0], point_b[1]-point_a[1])))
        #30장이나 찍는 이유는 "소탕 완료" 버튼이 애니메이션이 적용 되어 있어서 좀더 바른 검출을 위해서!

#몬스터를 소탕 후 가방을 비워주는 매크로 동작
def do_bag_clean():
    time.sleep(2)
    while operating:
        target = pyautogui.locateOnScreen('bag.png')
        if target != None:
            time.sleep(3)
            pyautogui.click(pyautogui.center(target))
            break
    while operating:
        target = pyautogui.locateOnScreen('clean.png')
        if target != None:
            time.sleep(3)
            pyautogui.click(pyautogui.center(target))
            break
    while operating:
        target = pyautogui.locateOnScreen('clean2.png')
        if target != None:
            time.sleep(3)
            pyautogui.click(pyautogui.center(target))
            break
    while operating:
        target = pyautogui.locateOnScreen('exit.png')
        if target != None:
            time.sleep(3)
            pyautogui.click(pyautogui.center(target))
            break
    time.sleep(3)
    pyautogui.click(point_c)


#매크로 과정을 데몬 프로세스로 실행 (tkinter 특성 상 어쩔 수 없는 선택..)
def demon_macro():
    global operating
    flag=0
    target=0
    while operating:
        for i in mac:
            target = pyautogui.locateOnScreen(i)
            if target != None:
                flag=1
                break
            if operating == 0:
                break
        if operating == 0:
                break
        if flag:
            flag = 0
            pyautogui.click(pyautogui.center(target))
            while operating:
                target = pyautogui.locateOnScreen('x.png')
                if target != None:
                    time.sleep(3)
                    pyautogui.click(pyautogui.center(target))
                    do_bag_clean()
                    break
        time.sleep(10)

#시작 버튼을 누르면 실행됨, 한번 누르는거만 적용되게 하려고 operating flag 사용
def do_macro():
    global operating
    if mac == []:
        messagebox.showinfo("오류","먼저 사진 저장 해주기!")
        return
    if operating :
        messagebox.showinfo("오류","이미 실행중!")
        return
    messagebox.showinfo("알림","시작!")
    operating=1
    d_process = threading.Thread(target=demon_macro)
    d_process.daemon = True
    d_process.start()

#키보드 인터럽트나 종료 버튼을 누르면 operating flag를 0으로 클리어 한 후 매크로 프로세스 종료
def end_macro(event=None):
    global operating
    operating = 0
    messagebox.showinfo("알림","중지 됨!")



last = tkinter.Frame(window)
button1=tkinter.Button(last,text='사진저장', width=13, height = 2,command=set_macro)
button1.grid(row=0,column=0)
button2=tkinter.Button(last,text='시작', width=13, height = 2,command=do_macro)
button2.grid(row=0,column=1)
button3=tkinter.Button(last,text='중지(x)', width=13, height = 2,command=end_macro)
button3.grid(row=0,column=2)
last.pack()

def set_point_f(event):
    global point_a
    point_a=pyautogui.position()
    text2.configure(text=str(point_a))

def set_point_b(event):
    global point_b
    point_b=pyautogui.position()
    text4.configure(text=str(point_b))

def set_point_c(event):
    global point_c
    point_c=pyautogui.position()
    text6.configure(text=str(point_c))

#마우스 좌표 설정을 위한 이벤트 처리
window.bind('<q>',set_point_f)
window.bind('<w>',set_point_b)
window.bind('<e>',set_point_c)
window.bind('<x>',end_macro)
window.mainloop()