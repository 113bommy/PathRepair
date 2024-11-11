from sys import stdin,stdout
from collections import Counter

t = int(stdin.readline().strip())
for _ in range(t):
    n,m = map(int,stdin.readline().split())
    alist = list(map(int,stdin.readline().split()))
    cnt = Counter(alist)
    mx = max(cnt.keys())
    k,div=1,0
    while k<n:
        if n&k:
            if cnt[k] == 0:
                j=k
                possible = False
                while j<=mx:
                    if cnt[j] > 0:
                        cnt[j]-=1
                        possible = True
                        break
                    cnt[j]+=1
                    div+=1
                    j*=2
                if not possible:
                    div = -1
                    break
            cnt[k]-=1
        cnt[k*2] += cnt[k]//2
        k*=2
    stdout.write("{}\n".format(div))
