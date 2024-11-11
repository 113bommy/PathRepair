l1, r1, l2, r2, k = map(int, input().split(" "))
l, r = max(l1, l2), min(r1, r2)
if l >= r:
    print(0)
elif k >= l and k <= r:
    print(r-l)
else:
    print(r-l+1)
