n = int(input())
k = int(input())
a = int(input())
b = int(input())

if n == 1:
    print(0)
    exit()

if k == 1:
    print((n-1)*a)
    exit()

ans = 0
while n != 1:
    q, r = divmod(n, k)
    if q == 0:
        ans += (r-1)*a
        n = 1
    else:
        if r == 0:
            ans += min(b, (n-n//k)*a)
            n //= k
        else:
            ans += r*a
            ans += min(b, (n-n//k)*a)
            n //=k
    #print(n, ans)
print(ans)
