[n, k, l, c, d, p, nl, np] = [int(x) for x in input().split()]
print(min(k*l//nl, c*d, p//np)//n)
