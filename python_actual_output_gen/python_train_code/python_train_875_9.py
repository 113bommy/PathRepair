n, m = map(int, input().split())
a = []
for i in range(m):
    a += list(map(int, input().split()))
for i in range(n):
    print(a.count(i))