def solve():
    n = int(input())
    x = n
    ans = 0
    d = 1
    while(x>10):
        x = x//10
        d = d*10+1
        ans += 9  
    ans += n//d
    print(ans)


for _ in range(int(input())):
    solve()