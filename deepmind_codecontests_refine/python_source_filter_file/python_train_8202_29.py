def f(n):
    x = 1
    ans = 0
    while x ** 2 - x < n:
        if n % x == 0:
            ans += n // x - 1
        x += 1
    print(ans)

n = int(input())
f(n)
