n = int(input())
a, b = map(int, input().split())
k = b
mk = -1
for i in range(1, n):
    if k > mk:
        mk = k
    a, b = map(int, input().split())
    k += b - a
print(mk)
