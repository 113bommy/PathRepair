n = int(input())
a = list(map(int, input().split()))
a.sort()
ai = a[-1]
aj = a[0]
for i in a[:-1]:
    if abs(ai/2-i) < abs(ai/2-aj):
        aj = i
print(ai, aj)