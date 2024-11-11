q = int(input())
res = []
for _ in range(q):
    n,a, b = [int(x) for x in input().split()]
    sa = 2 * a

    if b > sa:
        res += [int(n*a)]
    else:
        res += [int((n//2)*b + a)]
for e in res:
    print(e)
