x, y = map(int, input().split())
ans = 0
if y % x == 0:
    ans = -1
else:
    ans = x
print(ans) 