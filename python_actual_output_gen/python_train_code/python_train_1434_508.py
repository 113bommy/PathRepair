a,b=map(int,input().split())
t=a
n=1
while t<b:
    n+=1
    t+=a-1
print(n)