def solve():
    m= (n+1)//2
    ans = 0
    for i in range(1, m):
        ans+= 8* i*i
    print(ans)
    return




t = int(input())
for i in range(1, t + 1):
    n = int(input())
    #a , b = [int(i) for i in input().split(" ")]
    solve()