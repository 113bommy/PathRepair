def Func():
    x1 , y1, x2, y2 = map(int, input().split())
    x , y = map(int, input().split())
    print("YES") if abs(x1 - x2) % x == 0 and abs(y1 - y2) % y == 0 and \
    (abs(x1 -x2) / x) % 2 == (abs(y1 - y2) / y) % 2 else print("NO") 
Func()
    
    
