x, y = [int(x) for x in input().split(' ')]

triset = [y] * 3
c = 0

while sum(triset) < x*3:
    triset.sort()
    triset[0] = triset[2] + triset[1] - 1
    if triset[0] > x: triset[2] = x
    c += 1

print(c+1)
