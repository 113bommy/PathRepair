n, k, l, c, d, p, nl, np = map(int, input().split())
print(int(min((k*l)//nl, c*d, p/np)//n))