import heapq as hq
n=int(input())
s=input()
a=list(map(int,input().split()))
pre=[i-1 for i in range(n)]
nxt=[i+1 for i in range(n)]
free=[1 for i in range(n)]
line=[(abs(a[i]-a[i+1]),i,i+1) for i in range(n-1) if s[i]!=s[i+1]]
#print(line)
hq.heapify(line)
ans=[]

while line:
    t,ppre,pnxt=hq.heappop(line)
    if free[ppre] and free[pnxt]:
        ans.append(str(ppre+1)+''+str(pnxt+1))
        free[ppre],free[pnxt]=0,0
        if ppre==0 or pnxt==n-1:
            continue
        preppre,nxtpnxt=pre[ppre],nxt[pnxt]
        nxt[preppre],pre[nxtpnxt]=nxtpnxt,preppre
        if s[preppre]!=s[nxtpnxt]:
            hq.heappush(line,(abs(a[preppre]-a[nxtpnxt]),preppre,nxtpnxt))
print(len(ans))
print('\n'.join(ans))