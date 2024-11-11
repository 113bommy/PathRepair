n, k = map(int, input().split())
b = set()
m = 0
for i in range(k + 1):
    b.add(str(i))
for i in range(n):
    s = set(input())
    if s == b:
        m += 1
print(m)
