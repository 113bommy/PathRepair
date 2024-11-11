_=int(input())
for __ in range(_):
    a,b,x,y=list(map(int,input().split()))
    res=0
    res=max(res,(a-x-1)*y)
    res=max(res,a*(b-y-1))
    res=max(res,(x)*y)
    res=max(res,a*(y))
    print(res)