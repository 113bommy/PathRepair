n,m = [int(i) for i in input().split()]
if 2 < n and 2 < m:
    print((n-2)*(m-2))
elif 2 < n:
    print((n-2)*m)
elif 2 < m:
    print(n*(m-2))
else:
    print(n*m)