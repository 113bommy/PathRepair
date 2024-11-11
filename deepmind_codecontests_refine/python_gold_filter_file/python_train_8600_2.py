n=int(input())
for i in range(n):
    a=int(input())
    f=0
    if a%4==0:
        print(a//4)
    elif (a-6)%4==0 and a-6>-1:
        print(1+(a-6)//4)
    elif (a-9)%4==0 and (a-9)>-1:
        print(1+(a-9)//4)
    elif (a-15)%4==0 and (a-15)>-1:
        print(2+(a-15)//4)
    else:
        print(-1)