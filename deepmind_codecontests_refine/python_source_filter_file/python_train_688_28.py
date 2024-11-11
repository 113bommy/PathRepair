def f(n):
    a=b=1
    while True:
        if b > n:
            return
        yield b
        c = a+b
        a = b
        b = c
n = int(input())
s = [False for _ in range(n)]
for i in f(n):
    s[i-1] = True
s = ''.join([('O' if p else 'o') for p in s])