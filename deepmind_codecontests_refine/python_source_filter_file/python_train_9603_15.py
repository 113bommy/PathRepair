t=int(input())
for i in range(t):
    a1,b1,c1,d1=input().split(" ")
    a=int(a1)
    b=int(b1)
    c=int(c1)
    d=int(d1)
    s=k=b
    if (b>=a):
        print(b)
    else:
        if (d>=c):
            print(-1)
        else:
            if ((a-b) % (c-d)==0):
                k=int((a-b) % (c-d))
            else:
                k=int((a-b) % (c-d))+1 
            s=s+k*c
            print(s)