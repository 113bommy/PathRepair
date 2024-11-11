x, y, m = map(int, input().split())
k = 0
if(x > y):
	x,y = y,x
if x == m or y == m:
    print(0)
elif x < 0 and y < 0 and m > 0:
    print(-1)
elif x > 0 and y > 0 and m < 0:
    print(-1)
elif (x + y) <= x and (x + y) <= y:
    print(-1)
else:
    k = (y - x + y - 1) // y;
    x += y * k;
    while x < m and y < m:
        if x < y:
            x = x + y
        else:
            y = x + y
        k += 1;
    print(k)