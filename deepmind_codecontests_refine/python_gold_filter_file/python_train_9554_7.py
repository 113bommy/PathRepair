H, W, M = map(int, input().split())
 
h = [0] * H
w = [0] * W
Mem = [tuple(map(int, input().split())) for _ in range(M) ]
for i, j in Mem:
  h[i-1] += 1
  w[j-1] += 1

maxh = max(h)
maxw = max(w)
 
listh = {i for i, v in enumerate(h, 1) if v == maxh}
listw = {j for j, v in enumerate(w, 1) if v == maxw}

cnt = len(listh) * len(listw)

for i, j in Mem:
  if i in listh and j in listw:
    cnt -= 1
 
if cnt:
  ans = maxh + maxw
else:
  ans = maxh + maxw - 1

print(ans)