m,d=map(int,input().split())
a=[]
if m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12:
    for i in range(d,8):
        a.append(1)
    c=(31-len(a))/7
    if c>4:
        print(6)
    else:
        print(5)    
if m==4 or m==6 or m==9 or m==11:
    for i in range(d,8):
        a.append(1)
    c=(30-len(a))/7
    if c<=4:
        print(5)
    else:
        print(6)
if m==2:
    for i in range(d,8):
        a.append(1)
    c=(28-len(a))/7
    if c==3:
        print(4)
    if c<=4:
        print(5)
    