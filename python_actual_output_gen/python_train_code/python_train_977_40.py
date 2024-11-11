n, m, d = map(int, input().split())

if d == 0:
    print((n-1)/n)
else:
    print(2*(n-d)*(m-1)/n/n)