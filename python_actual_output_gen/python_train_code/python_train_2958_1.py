n,d,h=list(map(int,input().split()))
if d>2*h or d<h or (d==1 and d==h) :
    print(-1)
elif d!=h:
    for i in range(1,h+1):
        print(i,i+1)
    t=i+2
    if t<=n:    
        print(1,t)
    for i in range(t,t+d-h-1):
        print(i,i+1)
    for i in range(t+d-h,n+1):
        print(1,i)
else:
    for i in range(1,h+1):
        print(i,i+1)
    t=i+2
    for i in range(t+d-h,n+1):
        print(2,i)