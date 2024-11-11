n = int(input())
a = list(map(int, input().split()))
if n == 1:
    print(1,1)
    print(-1*a[0])
    print(1,1)
    print(0)
    print(1,1)
    print(0)
else:
    print(2,n)
    for i in range(1,n):
        if a[i]%n != 0:
            val1 = a[i]%n
            val = (n-1)*val1
            print(val,end=' ')
            a[i] = val1*n
        else:
            print(0,end=' ')
    print()
    print(1,n)
    print(0,end=' ')
    for i in range(1,n):
        print(-1*a[i],end=' ')
    print()
    print(1,1)
    print(-1*a[0])
