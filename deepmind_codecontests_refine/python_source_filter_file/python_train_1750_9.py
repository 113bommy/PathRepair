H, W, N = map(int, input().split())
sr, sc = map(int, input().split())
S = input()
T = input()

flag = 0
hidari = sc
migi = sc
ue = sr
shita = sr
for i in range(N):
  if S[i] == 'L':
    hidari -= 1
  if S[i] == 'R':
    migi += 1
  if S[i] == 'U':
    ue -= 1
  if S[i] == 'D':
    shita += 1
  if hidari == 0 or migi == W+1 or ue == H+1 or shita == 0:
    flag = 1
  
  if T[i] == 'R' and hidari != W:
    hidari += 1
  if T[i] == 'L' and migi != 1:
    migi -= 1
  if T[i] == 'D' and ue != 1:
    ue += 1
  if T[i] == 'U' and shita != H:
    shita -= 1

if flag :
  print("NO")
else :
  print("YES")
  