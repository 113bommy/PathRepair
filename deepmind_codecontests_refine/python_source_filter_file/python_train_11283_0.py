n, k = map(int, input().split())
tot = 0
for i in range(n):
    l, r = map(int, input().split())
    if l == r: tot += 1
    else: tot += r - (l-1)
if tot % k == 0: print(0)
else: print(k-(tot%7))