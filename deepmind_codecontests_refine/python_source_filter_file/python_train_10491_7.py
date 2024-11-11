n, k = map(int, input().split())
a = list(map(int, input().split()))
b = []
c = []
d = 1
m = 10**9+7
for i in range(n):
    if a[i] < 0:
        c.append(a[i])
    else:
        b.append(a[i])
b.sort()
c.sort(reverse=True)
if len(b) == 0 and k%2 == 1:
    for i in range(k):
        d = d*a[i]%m
else:
    while k > 0:
        if len(b) > 1 and len(c) > 1:
            if b[-1]*b[-2] < c[-1]*c[-2] and k > 1:
                d = d*c.pop()%m
                d = d*c.pop()%m
                k -= 2
            else:
                d = d*b.pop()%m
                k -= 1
        elif len(b) == 1 and len(c) > 1:
            if k > 1:
                d = d*c.pop()%m
                d = d*c.pop()%m
                k -= 2
            else:
                d = d*b.pop()%m
                k -= 1
        elif len(b) >= 1 and len(c) <= 1:
            d = d*b.pop()%m
            k -= 1
        else:
            d = d*c.pop()%m
            k -= 1
print(d)