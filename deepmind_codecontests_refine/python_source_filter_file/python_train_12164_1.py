def velsup(a,b,c,x):
    if a<=x<=b:
        return c
    elif x<a:
        return (a-x)+c
    else:
        return (x-b)+c

N=int(input())
t=[int(i) for i in input().split()]
v=[int(i) for i in input().split()]
S=[0 for i in range(N+1)]
for i in range(N):
    S[i+1]=t[i]+S[i]
TT=S[N]
vt=[0 for i in range(2*TT+1)]
for tt in range(TT*2+1):
    ta=tt/2
    va=min(velsup(-1,0,0,ta),velsup(TT,TT+1,0,ta))
    for i in range(N):
        va=min(va,velsup(S[i],S[i+1],v[i],ta))
    vt[tt]=va
ans=0
for i in range(2*TT):
    ans+=(vt[i]+vt[i+1])*0.25
print(ans)