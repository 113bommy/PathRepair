from math import gcd
_, *e = [[*map(int, t.split())] for t in open(0)]
ans = 1
mod = 10 ** 9 + 7
slope_dict = {}
zeros = 0
for x, y in e:
    if x == y == 0:
        zeros += 1
    else:
        d = gcd(x, y)
        x /= d
        y /= d
        if x < 0 or x == 0 < y:
            x, y = -x, -y
        s = 0
        if y < 0:
            x, y, s = -y, x, 1
        if (x, y) not in slope_dict:
            slope_dict[(x, y)] = [0, 0]
        slope_dict[(x, y)][s] += 1

for k in slope_dict:
    ans = ans * (pow(2, slope_dict[k][0], mod) +
                 pow(2, slope_dict[k][1], mod) - 1) % mod
print(ans + zeros - 1 % mod)
