m, n = map(int, input().split())
for i in range(min(m,n)):
    m -= i*2 + 1
    n -= i*2 + 2
    if m < 0:
        print('Vladik')
        break
    elif n < 0:
        print('Valera')
        break
