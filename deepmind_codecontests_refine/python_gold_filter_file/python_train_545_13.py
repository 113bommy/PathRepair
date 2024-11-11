n = int(input())
a = list(map(int,input().split()))

if n == 1:
    print(1,1)
    print(0)

    print(1,1)
    print(0)

    print(1,1)
    print(-a[0])
    exit()

A = [-1]*(n-1)
B = [0]*(n-1)
C = [-1]*n

A = [(n + a[i])*(n-1) for i in range(n-1)]
B[-1] = (n + a[-1])*(n-1)
C = [(1-n-a[i])*n for i in range(n)]

print(1,n-1)
print(*A)

print(2,n)
print(*B)

print(1,n)
print(*C)
