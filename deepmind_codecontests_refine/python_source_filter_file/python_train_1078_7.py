n=int(input())
if n==1 or n==2:
    print(-1)
 
if n==3:
    print(210)
else:
    x=10**(n-1)
    while x%210!=0:
        x=x+1
    print(x)    