t = int(input()) 
#n, m = map(int, input().split())
#s = input()
#c = list(map(int, input().split()))
for i in range(t):
    n = int(input())
    l = -1
    k = 0
    while 2 ** k <= n:
        k += 1
    if n > 1:
        l -= 2
    if n > 2:
        l += 3
    if n > 3:
        l -= 2 ** 2
        for i in range(3, k):
            a = 2 ** (i - 1)
            b = 2 ** i
            l -= b
            l += (b + a) * (b - a - 1) // 2
        if 2 ** (k - 1) < n:
            l += (2 ** (k - 1) + 1 + n) * (n - 2 ** (k - 1)) // 2
    print(l)
    