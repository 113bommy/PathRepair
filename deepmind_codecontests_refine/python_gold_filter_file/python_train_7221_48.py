for x in range(6):
    arr = list(map(int, input().split()))
    if 1 in arr:
        break
y = arr.index(1)
x = x+1
y = y+1
steps = abs(3-x) +  abs(y-3)
if steps >0:
	print(steps)
else:
	print(-1 * steps)

