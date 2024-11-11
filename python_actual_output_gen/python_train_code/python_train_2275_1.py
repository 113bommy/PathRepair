n, k = map(int, input().split())
a = list(map(int, input().split()))
p = [0]
for x in a[::-1]:
    p.append(p[-1] + x)
print(p[-1] + sum(sorted(p[1:-1])[n - k + 1:]))