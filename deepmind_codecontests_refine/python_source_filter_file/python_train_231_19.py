t = int(input())
for i in range(t):
    n = int(input())
    ans = 0
    while n > 1 and n % 2 == 0:
        if n % 3 == 0:
            n = n // 6
        else:
            n = n // 2
        
        ans += 1
    
    if n != 1:
        print(ans)
    else:
        print(-1)