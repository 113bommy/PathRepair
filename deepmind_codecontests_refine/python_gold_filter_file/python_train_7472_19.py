import sys
input = sys.stdin.readline
N = int(input())
css = [0] * N
mns = [0] * N
t = [x for x in range(N)]
for x in range(N):
  S = list(input())[: -1]
  for i in range(len(S)):
    if S[i] == "(": css[x] += 1
    if S[i] == ")":
      css[x] -= 1
      mns[x] = min(mns[x], css[x])
if sum(css):
  print("No")
  exit(0)
t.sort(key = lambda x: -10 ** 7 if mns[x] == 0 else -10 ** 7 - mns[x] if css[x] >= 0 else mns[x] - css[x])
l = 0
for i in t:
  if l + mns[i] < 0:
    print("No")
    exit(0)
  l += css[i]
print("Yes")