a, b = map(int, input().strip().split())
diffs = min(a, b)
a -= diffs
b -= diffs
sames = 0
if a != 0:
    if a % 2 == 0:
        sames += a//2
    else:
        sames += (a - 1)//2
if b != 0:
    if b % 2 == 0:
        sames += b
    else:
        sames += b - 1
print(diffs, sames)