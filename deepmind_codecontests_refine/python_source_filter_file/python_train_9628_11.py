n, k = tuple(map(int, input().split()))

land = [['S' for i in range(n)] for j in range(n)]

maxi = (n - n % 2) ** 2 // 2 + (n % 2) * 2 * n 
if k > maxi:
    print('NO')
else:
    print('YES')
    counter = 0
    land = [['S' for i in range(n)] for j in range(n)]
    for i in range(n):
        if counter >= k: break
        for j in range(i % 2, n, 2):
            if counter >= k: break
            land[i][j] = 'L'
            counter += 1
            
    for i in range(n):
        print(''.join(land[i]))