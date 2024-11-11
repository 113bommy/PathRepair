a,b = map(int, input().split())
time, dopA = 0, 0
if a>=1 and a<=1000 and b>=2 and b<=1000:
    while a != 0:
        a -=1
        time +=1
        dopA +=1
        if dopA == b:
            a +=1
            dopA = 0
        print(time)
else:
    if b ==0:
        print(a)
    print("0")