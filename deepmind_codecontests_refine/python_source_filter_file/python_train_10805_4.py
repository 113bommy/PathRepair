import time
n=int(input())
al=[list(map(int,input().split())) for _ in range(n)]
m=n*(n-1)//2
tn=[n-1]*n
start=time.time()
for i in range(m+1):
    flg=True
    s=0
    ts=set()
    for j in range(n):
        if tn[j]>0 and j not in ts:
            t=al[j][0]-1
            if t not in ts:
                if al[t][0]==j+1:
                    al[t].pop(0)
                    tn[t]-=1
                    ts.add(t)
                    al[j].pop(0)
                    tn[j]-=1
                    flg=False
        ts.add(j)
        s+=tn[j]
    if s==0:
        print(i+1)
        exit()
    if flg:
        print(-1)
        exit()
    now=time.time()
    if (now-start)>1.8:
        print(m)
        exit()