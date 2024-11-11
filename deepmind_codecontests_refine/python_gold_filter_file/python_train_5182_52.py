N,K = map(int,input().split())
P = list(map(int,input().split()))
C = list(map(int,input().split()))

ans = -1*float('inf')

for i in range(N):
    k = i
    Cc = []
    Ct = 0
    while 1:
        k = P[k]-1
        Cc.append(C[k])
        if i == k:
            break
    l = len(Cc)
    Ct = sum(Cc)
    t = 0
    for j in range(l):
        t += Cc[j]
        if j >= K:break
        now = t
        if Ct > 0:
            e = (K-j-1)//l
            now +=  Ct*e
        ans = max(ans,now)
print(ans)