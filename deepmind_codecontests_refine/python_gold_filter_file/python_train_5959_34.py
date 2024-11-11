import sys
input = sys.stdin.readline

n,m,k = map(int,input().split())
ans = 'L'*(m-1) + 'U'*(n-1)

for _ in range(n) : 
    if(_) : ans += 'D'
    ans += "RL"[_%2]*(m-1)
assert(len(ans) <= 2 * m * n)
print(len(ans))
print(ans)