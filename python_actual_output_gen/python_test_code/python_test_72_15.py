n,m = map(int,input().split())
a=[0]*n
w=[0]*n
ac=0
wa=0
for _ in range(m):
    p,s=input().split()
    p=int(p)-1
    if a[p]==0:
        if s=="AC":
            a[p]=1
            ac+=1
            wc+=w[p]
        else:
            w[p]+=1
print(ac,wc)