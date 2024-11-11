n = int(input())
a = list(map(int, input().split()))

infinite = False
points = 0

for i in range(1, n):
    if (a[i - 1], a[i]) in [(2, 3), (3, 2)]:
        infinite = True
    
    if (a[i - 1], a[i]) in [(2, 1), (1, 2)]:
        points += 3
    if (a[i - 1], a[i]) in [(3, 1), (1, 3)]:
        points += 4
    if i > 1 and (a[i - 2], a[i - 1], a[i]) == (1, 2, 3):
        points -= 1

if infinite:
    print("Infinite")
else:
    print("Finite\n{}".format(points))
