import math
k=int(input())
e=math.pow(10,18)
f=0
s=""
if k>=36:
    print(-1)
elif k==0:
    print(1)
elif k==1:
    print(6)
elif k==2:
    print(8)
else:
    if k%2!=0:
        for i in range(k//2):
            s+='8'
            if int(s)>=e:
                print(-1)
                f=1
                break
        if f==0:
            print(s+"4")
    else:
        for i in range(k//2):
            s+='8'
            if int(s)>=e:
                print(-1)
                f=1
                break
        if f==0:
            print(s)
