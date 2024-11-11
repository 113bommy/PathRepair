n, q = 0, []

with open(0) as f:
  n = int(f.readline())
  q = list(map(int, f.readline().split()))

q.sort()
num, time = 0, 0
for i in range(n):
  if q[i] > time:
    num += 1
    time += q[i]

print(num)