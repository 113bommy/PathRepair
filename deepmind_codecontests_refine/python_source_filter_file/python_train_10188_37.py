import sys
input = sys.stdin.readline
N = int(input())
p = list(map(int, input().split()))
res = [0] * N
for i in range(N):
  res[p[i] - 1] = 10 ** 9 - i

a = [1]
b = [res[0] - 1]
for i in range(1, N):
  if res[i] - a[-1] - 1 >= b[-1]:
    b.append(b[-1] - 1)
    a.append(res[i] - b[-1])
  else:
    a.append(a[-1] + 1)
    b.append(res[i] - a[-1])
print(*a)
print(*b)