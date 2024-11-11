def f(n, m):
    if n == 1:
        return [1]
    l = f(n - 1, m // 2);
    d = l.index(n - 1);
    l.insert(d + m % 2, n);
    return l
print(*f(*map(int, input().split())))