x, y = map(int, input().split())
ans = 0
if x % y == 0:
    ans = -1
else:
    ans = x
print(ans) 