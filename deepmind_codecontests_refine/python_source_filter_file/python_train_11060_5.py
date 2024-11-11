for _ in range(int(input())):
    n = int(input())
    x = n // 2
    if x % 2 != 0:
        print('NO')
    else:
        even, odd = [], []
        s = 0
        for _ in range(x):
            s += 2
            even.append(s)
            odd.append(s - 1)
        odd[-1] += x
        print('YES')
        print(even + odd)