n = int(input())

if n < 10:
    print(n)                                           
elif n < 190:
    if n & 1:
        print(((n - 10) >> 1) % 10)
    else:
        print((n + 10) // 20)
else:
    n -= 190
    q, r = divmod(n, 3)
    n = 100 + q
    s = str(n)
    print(s[r])