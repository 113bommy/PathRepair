n = int(input())
t = list(map(int, input().split()))
p = {}
for i in t:
    p[i] = p.get(i, 0) + 1
print(sum(p[i] * p.get(i, 0) for i in p if i > 0) + (p.get(0, 0) * (p.get(0, 0) - 1)) // 2)