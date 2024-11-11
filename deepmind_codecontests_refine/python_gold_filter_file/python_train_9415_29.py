n,d=map(int,input().split())
x=list(map(int,input().split()))
s=sum(x)+(n-1)*10
if s>d:
    print(-1)
elif sum(x)==d:
    print(0)
else:
    print((d-sum(x))//5)