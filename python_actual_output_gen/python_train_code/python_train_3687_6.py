t=int(input())
for i in range(t):
    n,a,b,c,d=input().split()
    n=int(n)
    a=int(a)
    b=int(b)
    c=int(c)
    d=int(d)
    mn1=(a-b)*n
    mx1=(a+b)*n
    mn2=c-d
    mx2=c+d
    if mn1<mx2 or mx1<mn2:
        print("No")
    else:
        print("Yes")
    