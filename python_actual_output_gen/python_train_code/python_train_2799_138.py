n, k, l, c, d, p, nl, np = [int(s) for s in input().split()]

print(int((min((k*l)//n, c*d, p/np))/n))
