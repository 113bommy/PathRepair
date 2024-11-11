n, d = map(int, input().split())
m = int(input())
for i in range(m):
    x, y = map(int, input().split())
    if (x - y <= d and x - y >= -d) and (x + y <= 2*n - d and x + y >= d):
        print('Yes')
    else:
        print('No')

    
    