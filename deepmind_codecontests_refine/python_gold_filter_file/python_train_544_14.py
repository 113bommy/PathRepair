for i in range(int(input())):
    a=str(input())
    b=0
    while True:
        c=a.find("01")
        d=a.find("10")
        if c!=-1:
            b+=1
            a=a[:c]+a[c+2:]
        elif d!=-1:
            b+=1
            a=a[:d]+a[d+2:]
        else:break
    if b%2!=0:
        print("DA")
    else:print("NET")