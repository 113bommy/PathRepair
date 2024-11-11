n,d=map(int,input().split())
t=0
for i in range(n):
    a,b=map(int,input().split())
    if a*a+b*b<=d*d:
        t+=1
print(n)