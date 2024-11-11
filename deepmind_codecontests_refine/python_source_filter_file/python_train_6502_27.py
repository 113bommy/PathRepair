import math

n, m = map(int, input().split())

c_max = n - m + 1
c_min = math.floor(n/m)

# print(c_min, c_max)


def s(i):
    return round((i*(i-1))/2)


k_max = s(c_max)


if n % m:

    d = n // m
    o = n - m*d

    # print(o, d)
    # print(s(c_min)*(d-o), s(c_min+1)*(m-o))

    k_min = s(d)*(m-o) + s(d+1)*o

    # k_min1 = s(c_min)*(m-1)
    # k_min1 += s(n % c_min)
    #
    # c_min = math.floor(n/m)
    # k_min2 = s(c_min)*(m-1)
    # k_min2 += s(c_min + (n % m))
    #
    # k_min = min(k_min1, k_min2)
else:
    k_min = s(c_min)*m

print( k_min, k_max )