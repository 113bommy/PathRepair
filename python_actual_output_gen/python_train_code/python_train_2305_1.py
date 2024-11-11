n = int(input())
a = list(map(int, input().split()))
t = n * (n + 1) // 2
s = sum(a)
if s % t:
    print('NO')
else:
    c = s // t
    b = [0] * n
    for i in range(n):
        b[i] = a[i] - a[i - 1] - c
    for i in range(n):
        if b[i] % n or b[i] < 0:
            print('NO')
            break
    else:
        print('YES')
