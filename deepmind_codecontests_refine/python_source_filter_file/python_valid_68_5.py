import sys
input=sys.stdin.readline

t=int(input())
for i in range(t):
    n=int(input())
    x=int(n**(1/2))
    a=n-x*x
    if a==0:
        print(1,x)
        continue
    x+=1
    if a<=x:
        print(a,x)
    else:
        print(x,x*2-a)