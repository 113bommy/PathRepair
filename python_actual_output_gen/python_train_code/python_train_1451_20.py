for _ in range(int(input())):
    n, m = map(int, input().split())
    conv = []
    
    for i in range(n):
        row = list(input())
        conv.append(row)
    
    ans = 0
    for i in range(n):
        if conv[i][m - 1] == 'D':
            ans += 1
    for i in range(m):
        if conv[n - 1][i] == 'R':
            ans += 1        
    print(ans)
    