import sys

n = int(input())
a = list(map(int,input().split()))
mi,ma = 10 ** 6,0
cnt = [0] * n
for v in a:
    cnt[v] += 1
    mi = min(mi,v)
    ma = max(ma,v)
if ma - mi >= 2:
    print("No")
    sys.exit()
if mi != ma:
    if cnt[mi] == ma or (n - cnt[mi]) // (ma - cnt[mi]) < 2:
        print("No")
    else:
        print("Yes")
else:
    if mi == n - 1 or mi * 2 <= n:
        print("Yes")
    else:
        print("No")
