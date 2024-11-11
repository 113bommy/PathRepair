tc = int(input())
while tc:
    n, m = list(map(int, input().split()))
    if n - m == 3:
        print('YES')
    else:
        print('NO')
    tc -= 1