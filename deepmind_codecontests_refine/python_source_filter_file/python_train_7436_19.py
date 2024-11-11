n, m = map(int, input().split())
s = input()
if n - m < m:
    for i in range(n - m):
        print('RIGHT')
    s = s[::-1]
    for i in range(n):
        if i:
            print('LEFT')
        print('PRINT', s[i])
else:
    for i in range(m):
        print('LEFT')
    for i in range(n):
        if i:
            print('RIGHT')
        print('PRINT', s[i])
