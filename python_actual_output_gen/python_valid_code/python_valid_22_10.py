n = int(input())
a = list(map(int, input().split()))
chest = 0
biceps = 0
back = 0
for i in range(0, len(a), 3):
    chest += a[i]
for i in range(1, len(a), 3):
    biceps += a[i]
for i in range(2, len(a), 3):
    back += a[i]
if back < chest > biceps:
    print(chest)
elif chest < back > biceps:
    print(back)
else:
    print(biceps)
