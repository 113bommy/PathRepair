H, W, M = map(int, input().split())

HL, WL = [0]*H, [0]*W
B = []

for _ in range(M):
  h, w = map(lambda x:int(x)-1, input().split())
  B.append((h, w))
  HL[h] += 1
  WL[w] += 1

HM, WM = max(HL), max(WL)
K = HL.count(HM) * WL.count(WM)

cnt = 0
for h, w in B:
  if HL[h] == HM and WL[w] == WM:
    cnt += 1

if K > cnt:
  print(HM+WM)
else:
  print(HM+WM-1)
