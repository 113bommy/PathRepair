t=int(input())

for yo in range(t):
    l=input()
    l=l.split(" ")
    b=int(l[0])
    b-=1
    n=int(l[1])
    a=int(l[2])
    b1=int(l[3])
    a-=b1
    b-=(n*b1)
    val=b//a
    if(b<=0):
        print(-1)
    elif(val>n):
        print(n)
    else:
        print(val)