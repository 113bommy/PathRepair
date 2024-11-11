from math import gcd
def take_input(s):          #for integer inputs
    if s == 1:  return int(input())
    return map(int, input().split())

n,m = take_input(2)
grid = []
d = {}
for i in range(m):
    grid += list(take_input(3))
for i in range(0,m*3,3):
    if d.get(grid[i],0) > 0:
        if d.get(grid[i],0) == 1:
            d[grid[i+1]] = 2
            d[grid[i+2]] = 3
        elif d.get(grid[i],0) == 2:
            d[grid[i+1]] = 1
            d[grid[i+2]] = 3
        else:
            d[grid[i+1]] = 1
            d[grid[i+2]] = 2
    elif d.get(grid[i+1],0) > 0:
        if d.get(grid[i+1],0) == 1:
            d[grid[i]] = 2
            d[grid[i+2]] = 3
        elif d.get(grid[i+1],0) == 2:
            d[grid[i]] = 1
            d[grid[i+2]] = 3
        else:
            d[grid[i]] = 1
            d[grid[i+2]] = 2
    elif d.get(grid[i+2],0) > 0:
        if d.get(grid[i+2],0) == 1:
            d[grid[i]] = 2
            d[grid[i+1]] = 3
        elif d.get(grid[i+2],0) == 2:
            d[grid[i]] = 1
            d[grid[i+1]] = 3
        else:
            d[grid[i]] = 1
            d[grid[i+1]] = 2
    else:
        d[grid[i]] = 1
        d[grid[i+1]] = 2
        d[grid[i+2]] = 3
for i in range(n):
    print(d[i+1], end = " ")