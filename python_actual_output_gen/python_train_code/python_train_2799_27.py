n, k, l, c, d, p, nl, np = [int(x) for x in input().split()]
print(int(min((k*l)/nl,c*d,p*np)/n))