n = int(input())

d = {}

for _ in range(n):
    l = list(map(int, input().split()))
    for i in set(l):
        d.setdefault(i, 0)
        d[i] += 1

result = []
for key, item in d.items():
    if item == n:
        result.append(key)

print(*result)
