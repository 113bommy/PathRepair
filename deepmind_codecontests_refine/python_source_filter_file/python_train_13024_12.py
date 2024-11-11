def solve(y,z):
    coins = 0
    while z > 0:
        if z >= y:
            coins += (z/y)
            z %= y
        y -= 1
    return coins


y, z = [int(x) for x in input().split()]
print(round(solve(y,z)))