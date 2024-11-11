def solve(n):
    ans = [2*n]
    for i in range(n-1):
        ans.append(ans[-1]+2)
    return ans
    

t = int(input())
for i in range(t):
    n = int(input())
    print(*solve(n))