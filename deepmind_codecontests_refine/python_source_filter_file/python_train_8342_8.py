from collections import defaultdict; import sys; input = sys.stdin.readline

n = int(input())
a = [int(item) for item in input().split()]
pre = [0] * (n + 1)
for i in range(n):
    pre[i] = pre[i - 1] + a[i]

d = defaultdict(list)

for i in range(n):
    for j in range(i, n):
        d[pre[j] - pre[i - 1]] += [(i, j)]

# print(d)
overall_s = []
for v in d:
    pairs = d[v]
    pairs.sort(key=lambda pair:(pair[1], pair[0]))
    last = 0
    s = [pairs[0]]
    for i in range(1, len(pairs)):
        if pairs[i][0] >= pairs[last][1]:
            s.append(pairs[i])
            last = i
    if len(s) > len(overall_s):
        overall_s = s

print(len(overall_s))
for pair in overall_s:
    print(pair[0] + 1, pair[1] + 1)
