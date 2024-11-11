n, k, l, c, d, p, nl, np = list(map(int, input().split()))
print(min((k*l)//n, c*d, p//np)//n)