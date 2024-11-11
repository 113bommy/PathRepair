q = int(input())
for _ in range(q):
    n, m = map(int, input().split())
    k = m % 10
    ans = 0
    
    if k == 1 or k == 3 or k == 7 or k == 9:
        ans = ((n // m) // 10) * 45
        t = (n // m) % 10
        q = k
        for _ in range(t):
            ans += q % 10
            q += k
            
    elif k == 2 or k == 4 or k == 6 or k == 8:
        ans = ((n // m) // 5) * 20
        t = (n // m) % 5
        q = k
        for _ in range(t):
            ans += q % 10
            q += k
            
    elif k == 5:
        ans = ((n // m + 1) // 2) * 5
        
    elif k == 0:
        ans = 0
    print(ans)