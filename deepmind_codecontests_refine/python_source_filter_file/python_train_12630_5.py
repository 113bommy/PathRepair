t = int(input())

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    odd = 0
    for j in range(n):
        if a[j] % 2 == 1:
            odd += 1
    if odd >= n:
        print('Yes')
    else:
        print('No')

        
        
        