def multiply(x, y):
    global m
    a = (x[0][0] * y[0][0] + x[0][1] * y[1][0]) % m
    b = (x[0][0] * y[0][1] + x[0][1] * y[1][1]) % m
    c = (x[1][0] * y[0][0] + x[1][1] * y[1][0]) % m
    d = (x[1][0] * y[0][1] + x[1][1] * y[1][1]) % m
    return [[a, b], [c, d]]

def seqs(n):
    f = [[1, 1], [1, 0]]
    result = [[1, 0], [0, 1]]
    while n > 0:
        if n % 2 == 1:
            result = multiply(result, f)
            n -= 1
        f = multiply(f, f)
        n //= 2
    return result[0][1]

def power(n):
    global m
    result = 1
    base = 2
    while n > 0:
        if n % 2 == 1:
            result *= base
            n -= 1
        base *= base
        base %= m
        result %= m
        n //= 2
    return result

n, k, l, m = tuple(map(int, input().split()))

if k > 2 ** l:
    print(0)
else:
    if k != 0 and l == 0:
        answer = 0
    else:
        answer = 1
    s = seqs(n + 2)
    total = power(n)
    while l > 0:
        if k % 2 == 0:
            answer *= s
        else:
            answer *= total - s
        answer %= m
        k //= 2
        l -= 1

    print(answer % m)
