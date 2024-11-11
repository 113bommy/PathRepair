from collections import Counter

input()
c = Counter(map(int, input().split()))

max_ = max(c)
max_points = {1: c[1], 2: max(c[1], 2 * c[2])}

for i in range(3, max_ + 1):
    max_points[i] = max(max_points[i - 2] + i * c[i], max_points[i - 1])

print(max_points[max_])