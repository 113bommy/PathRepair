t = int(input())
for _ in range(t):
    n = int(input())
    k = (n - 1) // 2
    ans = 0
    for i in range(1, k + 1):
        ans += i**2
        
    print(8 * ans)