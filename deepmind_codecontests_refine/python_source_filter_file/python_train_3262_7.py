n, b = map(int, input().split())
a = list(float(x) for x in input().split())
s = max(a)
c = [0]*n
for i in range(n):
    m = s-a[i]
    b = b-m
    c[i] = c[i]+m
if b > 0:
    for i in range(n):
        c[i] = c[i] + b/n
    for i in range(n):
        print("%.6f" % c[i])
else:
    print("-1")