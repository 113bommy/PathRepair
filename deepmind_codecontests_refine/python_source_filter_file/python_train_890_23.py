def rec(n, z, l, x, y):
    if n > z:
        return l
    elif n == z:
        l.append(n)
        return l
    else:
        if n not in l:
            l.append(n)
        rec(n * x, z, l, x, y)
        rec(n * y, z, l, x, y)


def gcd(x, y):
    if x < y:
        x, y = y, x
    if y == 0:
        return x
    return gcd(y, x % y)


def lcm(x, y):
    if x < y:
        x, y = y, x
    gcd_ = gcd(x, y)
    return x * y // gcd_


def main_func():
    x, y, z = [int(i) for i in input().split(" ")]
    count = 0
    for i in range(z + 1):
        if not i % x and not i % y:
            count += 1

    return count

print(main_func())



