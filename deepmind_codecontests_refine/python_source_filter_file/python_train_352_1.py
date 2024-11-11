def prime(n):
    a=0
    b=0
    c=0
    while n%2==0: 
        n/=2
        a+=1
    while n%3==0:
        n/=3
        b+=1
    while n%5==0:
        n/=5
        c+=1
    return n,a,b,c
a,b=map(int,input().split())
if a==b:
    print(0)
    exit()
x,a1,a2,a3=prime(a)
y,b1,b2,b3=prime(a)
if x!=y:
    print(-1)
else:
    print(abs(a1-b1)+abs(a2-b2)+abs(a3-b3))