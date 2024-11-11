n, p = map(int, input().split())
a = list(map(int, input().split()))


a = sorted(a)
for i in range(n):
    a[i] -= i
l = max(a)

for i in range(n):
    a[i] += p - 1
r = min(a[p - 1:])

print(min(r - l, 0))
print(*[val for val in range(l, r)])