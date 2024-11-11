t = int(input())
for k in range(t):
    n = int(input())
    ls = list(map(int, input().split()))
    x = ls[0]
    i = 1
    while i<n and ls[i] == x:
        i+= 1
    if i == n:
        print('NO')
    else:
        print('YES')
        y = ls[i]
        for j in range(1, n):
            if ls[i] != x:
                print(j+1, 1)
            else:
                print(j+1, i)
