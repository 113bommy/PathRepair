from collections import defaultdict
H,W,M = list(map(int,input().split()))

h = [0] * H
w = [0] * W

hw = defaultdict(set)

for _ in range(M):
    a,b = list(map(int,input().split()))
    h[a - 1] += 1
    w[b - 1] += 1
    hw[a - 1].add(b - 1)
    
hm = max(h)
wm = max(w)

hp = [i for i, v in enumerate(h) if v == hm]
wp = [i for i, v in enumerate(w) if v == wm]

for x in hp:
    for y in wp:
        if y not in hw[x]:
            print(hm + wm)
            exit()
else:
    print(hm + wm - 1)

