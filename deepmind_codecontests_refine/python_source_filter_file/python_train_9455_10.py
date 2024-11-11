n = int(input())
a = list(map(int, input().split()))

ai = max(a)
aj = a[0]
for i in a:
    if abs(ai - 2*i) < abs(ai - 2*aj):
        aj = i

print(ai,aj)
