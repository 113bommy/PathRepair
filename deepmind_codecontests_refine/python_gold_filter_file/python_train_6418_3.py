n = int(input())
l = list(map(int, input().split()))
l.sort()
C = sum(l)
B = 0
R = B - C
for i in range(len(l) - 1, -1, -1):
    B += l[i]
    C -= l[i]
    if B - C >= R:
        R = B - C
    else:
        break
print(R)
