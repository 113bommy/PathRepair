n, k, l, c, d, p, nl, np = map(int, input().split())
print(min([k*l//n, c*d, p//np])//n)