import sys
input = sys.stdin.readline
N = int(input())
k = 0
for i in range(1, N + 1):
  if i * (i - 1) == N * 2:
    k = i
    break
if k == 0:
  print("No")
  exit(0)
res = [[] for _ in range(k + 1)]
p = 1
print("Yes")
print(k)
for i in range(2, k + 1):
  for j in range(1, i):
    res[i].append(p)
    res[j].append(p)
    p += 1
for i in range(1, k + 1):
  print(str(len(res[i])) + " " + " ".join(list(map(str, res[i]))))