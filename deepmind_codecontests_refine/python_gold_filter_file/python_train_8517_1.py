import sys
N=int(input())
if N==2:
    print(1)
    sys.exit()
if N==3:
    print(4)
    sys.exit()
mod=10**9+7
table=[1]*(N+3)
t=1
for i in range(1,N+3):
    t*=i
    t%=mod
    table[i]=t
rtable=[1]*(N+3)
t=1
for i in range(1,N+3):
    t*=pow(i,mod-2,mod)
    t%=mod
    rtable[i]=t
#print(table,rtable)
ans=0
l=0
for k in range(N):
    if 0>2*k-N:
        continue
    num=table[k]*table[N-1-k]
    div=table[k-1]*rtable[N-1-k]*rtable[k-1-(N-1-k)]
    div%=mod
    num*=div
    num%=mod
    ans+=k*(num-l)
    l=num
    l%=mod
    ans%=mod
    #print(k, num, div)
print(ans)