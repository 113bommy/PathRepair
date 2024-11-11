def f(x,y):
    return x&~y

t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int,input().strip().split()))
    b = [0 for i in range(n)]
    for i in range(1,n):
        b[i]=f(a[i]^a[i-1],a[i])
    for x in b:
        print(x,end=" ")
    print()
    