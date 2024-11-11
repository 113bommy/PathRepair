def f(n, m):
    res = 'YES'
    if (n + 1) % 2 == 0:
        if m < (n + 1) // 2: res = 'NO'
    else:
        if m <= (n + 1) // 2: res = 'NO'
    print(res)
        
    
for i in range(int(input())):
    m, n = map(int, input().split())
    f(n, m)
