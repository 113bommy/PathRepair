n, k, l, c, d, p, nl, nc = map(int, input().strip().split())
print( min((k*l)//nl, c*d, p//nc) // n)