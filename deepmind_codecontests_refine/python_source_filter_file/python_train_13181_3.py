n, m = map(int, input().split())
c = [0] * 16
for _ in range(n):
  c[int(''.join(input().split()), 2)] += 1
yes = 0
for i in range(1 << m):
  if c[i]:
    for j in range(i + 1, 1 << m):
      if 0 == (i & j) and c[j]:
        yes = 1
print('YES' if yes else 'NO')
