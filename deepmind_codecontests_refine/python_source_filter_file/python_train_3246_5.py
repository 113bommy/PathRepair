from collections import Counter

n, k = map(int, input().split())
a = [int(input()) for _ in range(n)]

odd = 0
for count in Counter(a).values():
    odd += 1

print(n - (odd // 2))
