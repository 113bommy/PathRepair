n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
S=sum(b)-sum(a)
if S<0:print("No")
else:
    cnt=0
    for i in range(n):
        cnt+=max((b[i]-a[i])//2,0)
    if cnt<=S:print('Yes')
    else:print("No")