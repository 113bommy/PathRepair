N=int(input())
T=list(map(int,input().split()))
A=list(map(int,input().split()))
mod=10**9+7

#0:高さ確定 1:高さそれ以下
for i in range(0,N):
    if i==0:
        T[i]=(T[i],0)
    else:
        h,query=T[i-1]
        if h==T[i]:
            T[i]=(T[i],1)
        else:
            T[i]=(T[i],0)

for i in range(0,N):
    if i==0:
        A[-i-1]=(A[-i-1],0)
    else:
        h,query=A[-i]
        if h==A[-i-1]:
            A[-i-1]=(A[-i-1],1)
        else:
            A[-i-1]=(A[-i-1],0)

ans=1
for i in range(0,N):
    h1,q1=T[i]
    h2,q2=A[i]
    if q1==0:
        if q2==0:
            if q1!=q2:
                ans=0
        else:
            if h1>h2:
                ans=0
    else:
        if q2==0:
            if h2>h1:
                ans=0
        else:
            ans=(ans*min(h1,h2))%mod

print(ans)