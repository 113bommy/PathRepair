n,s=map(int,input().split())
sem=[-1]*(100001)
bum=[-1]*(100001)
for i in range(n):
    wh,p,q=input().split()
    p=int(p)
    q=int(q)
    if wh=='B':
        if bum[p]==-1:
            bum[p]=0
        bum[p]+=q
    else:
        if sem[p]==-1:
            sem[p]=0
        sem[p]+=q
fins=[]
finb=[]
ts=s
for i in range(100000,-1,-1):
    if not ts:
        break
    if(bum[i]!=-1):
        finb.append((i,bum[i]))
        ts-=1
ts=s
for i in range(100001):
    if not ts:
        break
    if(sem[i]!=-1):
        fins.append((i,sem[i]))
        ts-=1
ts=s
for i in range(len(fins)-1,-1,-1):
    if not ts:
        break
    a,b=fins[i]
    print('S',a,b)
    ts-=1
ts=s
for i in range(len(fins)):
    if not ts:
        break
    a,b=finb[i]
    print('B',a,b)
    ts-=1









