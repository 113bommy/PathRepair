n, p, q = map(int, input().split())
s = input()
if n % p == 0:
    print(n // p)
    for i in range(n // p):
        print(s[p * i:p *(i + 1)])
elif n % q == 0:
    print(n // q)
    for i in range(n // q):
        print(s[q * i:q *(i + 1)])
else:
    ans = -1
    for i in range(1, n // p + 1):
        if (n - (p * i)) % q == 0:
            ans = i
    if ans == -1:
        print(-1)
        exit()
    print(ans + (n - p * ans) // q)
    for i in range(ans):
        print(s[p * i:p *(i + 1)])
    for i in range(ans * p, n, q):
        print(s[i:i + q])
