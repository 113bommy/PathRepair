n, m = map(int, input().split())
a = list(map(int, input().split()))
mi = 10 ** 9
for i in range(1, n + 1):
    mi = min(mi, a.count(n))
print(mi)