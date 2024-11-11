n = int(input())
A = list(map(int,input().split()))
A.sort()
if n == 1:
    print(*A)
elif n == 2:
    print((A[0] + A[1]) * 2)
else:
    k = 2
    s = 0
    for i in range(n - 1):
        s += k * A[i]
        k += 1
    s += A[-1] * (k - 1)
    print(s)