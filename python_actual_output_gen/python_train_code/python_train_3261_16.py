n = int(input())
a = list(map(int, input().split()))
a.sort()
ai = a[-1]
aj = ai
for i in a:
    if abs(ai/2-i) < abs(ai/2-aj):
        aj = i
print(ai, aj)