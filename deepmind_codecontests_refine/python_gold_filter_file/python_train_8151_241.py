n, k, l, c, d, p, nl, np = map(int, input().split())
l1 = (k*l)//nl
l2 = (c*d)
l3 = p//np

toasts = min(l1, l2, l3)
print((toasts//n))