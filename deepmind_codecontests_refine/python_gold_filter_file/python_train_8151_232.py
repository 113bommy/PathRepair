n, k, l, c, d, p, nl, np = map(int,input().split())
a = min(k*l//nl,c*d,p//np)//n
print(a)