v1,v2=list(map(int,input().split()))
t,d=list(map(int,input().split()))
ans=[0]*(t)
ans[0]=v1
ans[-1]=v2
n=t
for i in range(1,n-1):
    if ans[-1]<ans[i-1]+d:
        if ans[i-1]+d-ans[-1]<=d*(n-1-i):
            ans[i]=ans[i-1]+d
        else:
            ans[i]=ans[-1]+d
    else:
        ans[i]=ans[i-1]+d
print(sum(ans))