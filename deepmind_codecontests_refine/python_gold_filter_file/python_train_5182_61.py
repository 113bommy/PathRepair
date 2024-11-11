import sys
input = sys.stdin.readline
n,K=map(int,input().split())
p=list(map(lambda x:int(x)-1,input().split()))
c=list(map(int,input().split()))
if K == 1:
    print(max(c));exit()
ans = -10**10
def cycle(k):
    mo=k
    clen=0
    cscore=0
    flg = True
    cmax=[-10**10]
    while (mo != k or flg):
        clen+=1
        cscore+=c[mo]
        mo = p[mo]
        cmax.append(max(cmax[-1],cscore))
        if mo == k:
            flg = False
    if cscore<0:
        return cmax[min(K-1,clen-1)]
    return cscore*((K-1)//clen)+cmax[(K-1)%clen+1]
for i in range(n):
    a=cycle(i)
    if a>ans:
        ans = a
print(ans)
