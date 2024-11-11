n = int(input())
k = int(input())
a = int(input())
b = int(input())
ans = 0

if (k == 1):
    print(n * a);
else:
    while n != 1:
        if n % k:
            if (n > k):
                ans += (n % k) * a
                n -= n % k
            else:
                ans += (n - 1) * a;
                n = 1;
        else:
            ans += min((n - (n // k)) * a, b)
            n //= k
    print(ans)
