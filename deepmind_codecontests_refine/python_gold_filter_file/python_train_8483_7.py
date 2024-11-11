n,m = map(int,input().split())
l = 0
if n == m:
    if n % 2 == 0:
        print(n,0)
    else:
        print(n,0)
else:
    l = abs(n-m)
    if l % 2 == 0:
        if n > m:
            print(m,l//2)
        else:
            print(n,l//2)
    else:
        if n > m:
            print(m,l//2)
        else:
            print(n,(l//2))
