# 508A

__author__ = 'artyom'

read = lambda: map(int, input().split())
n, m, k = read()
a = [[False] * (m + 2) for _ in range(n + 2)]
for t in range(k):
  i, j = read()
  a[i][j] = True
  if any([all(a[i + p][j + q] for p, q in cs) for cs in [[[-1, -1], [-1, 0], [0, -1]],
                                                         [[0, -1], [-1, 1], [0, 1]],
                                                         [[-1, 0], [-1, 1], [0, 1]],
                                                         [[0, 1], [1, 0], [1, 1]]]]):
    print(t + 1)
    exit()
print(0)