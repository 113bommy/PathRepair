import sys
input = sys.stdin.readline
n, sx, sy = map(int, input().split())
top = 0
left = 0
right = 0
bottom = 0
for i in range(n):
    x, y = map(int, input().split())
    if y < sy:
        top += 1
    elif y > sy:
        bottom += 1
    if x > sx:
        right += 1
    elif x < sx:
        left += 1
if max(top, left, right, bottom) == top:
    print(top)
    print(sx, sy - 1)
elif max(top, left, right, bottom) == left:
    print(left)
    print(sx - 1, sy)
elif max(top, left, right, bottom) == right:
    print(right)
    print(sx + 1, sy)
else:
    print(bottom)
    print(sx, sy + 1)
