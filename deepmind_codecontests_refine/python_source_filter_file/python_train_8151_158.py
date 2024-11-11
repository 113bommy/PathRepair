n, k, l, c, d, p, nl, np = map(int, input().split())

print(min((l*k)/nl, c*d, p/np)//n)