n = int(input())
for i in range(n):
    a = list(map(int, input().strip().split()))
    k = a[0]
    v = a[1]
    if k < v:
        if (k*2) < (v):
             print((v)*(v))
        if k*2 == v:
             print(v*v)
        if k*2 > v:
             print((k*2)*(k*2))
            
    if k > v:
        if k < (v*2):
            print((v*2)*(v*2))
        if k == v*2:
            print((k*k))
        if k > v*2:
            print((k)*(k))
    if k == v:
        print(k*v*4)