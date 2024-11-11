n,d=map(int,input().split())
t=list(map(int,input().split()))
if((d-sum(t)-(5*(len(t)-1)))%5==0):
    print((d-sum(t))//5)
else:
    print(-1)