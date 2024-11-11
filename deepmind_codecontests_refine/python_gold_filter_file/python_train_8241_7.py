def lastDigits(m):
    a = []
    for i in range(1,11):
        k = (i*m)%10
        if k not in a:
            a.append(k)
    return a

q = int(input())
for _ in range(q):
    n, m = [int(x) for x in input().split()]
    sm,b = 0,0
    if n>=m :
        if n>10:
            ldSeries = lastDigits(m%10)
            l = len(ldSeries)
            z = n//m
            k = z%l
            z -= k
            sm += (z//l)*sum(ldSeries)
            b = sum(ldSeries[:k])
        else:
            for i in range(m,n+1,m):
                sm += i%10
    print(sm+b)