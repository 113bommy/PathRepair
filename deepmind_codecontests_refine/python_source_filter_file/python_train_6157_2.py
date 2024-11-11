sx, sy = input().split(' ')
dx, dy = input().split(' ')
sx = int(sx)
sy = int(sy)
dx = int(dx)
dy = int(dy)
n = int(input())
s = input()
if sx == dx and sy == dy:
    print(0)
    exit(0)
low = 1 
high = 2 * (10 ** 9)
ans = -1
while low <= high:
    mid = (low + high) // 2
    cx = 0
    cy = 0
    for c in s:
    	if c == 'L':
    		cx -= 1
    	elif c == 'R':
    		cx += 1
    	elif c == 'U':
    		cy += 1
    	else:
    		cy -= 1
    cx = sx + (mid // n) * cx
    cy = sy + (mid // n) * cy
    for i in range(mid % n):
    	c = s[i]
    	if c == 'L':
    		cx -= 1
    	elif c == 'R':
    		cx += 1
    	elif c == 'U':
    		cy += 1
    	else:
    		cy -= 1
    dis = abs(cx - dx) + abs(cy - dy)
    if dis <= mid:
    	ans = mid
    	high = mid - 1
    else:
    	low = mid + 1
print(ans)