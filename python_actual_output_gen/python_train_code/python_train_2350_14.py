T=int(input())
for i in range(T):
    a,b=input().split()
    b=int(b)
    if b<9:
        print("0")
    else:
        a=int(a)
        c=0
        c=a
        x=9
        x=x*10+9
        while(x<b):
            c=c+a
            x=x*10+9
        print(c)
  
