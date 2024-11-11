import sys
input = sys.stdin.readline

x, y = map(int, input().split())
if x%y == 0:
    ans = -1
else:
    ans = x
print(ans)