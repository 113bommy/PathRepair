for t in range(int(input())):
    n = int(input())
    ans = 0
    for x in range(1, (n + 1) // 2):
        ans += x ** 2
        
    print(ans*8)