from itertools import accumulate

n = int(input())
a = [[0] * 10 for _ in range(10)]
for x1, y1, x2, y2 in (map(int, input().split()) for _ in range(n)):
    a[x1][y1] += 1
    a[x1][y2] -= 1
    a[x2][y1] -= 1
    a[x2][y2] += 1
print(max(map(max, map(accumulate, zip(*map(accumulate, a))))))