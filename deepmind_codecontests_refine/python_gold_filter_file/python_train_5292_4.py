def solve():
    ans = 0
    N = int(input())
    miny = float('inf')
    ans = 0
    x = [0]*N
    y = [0]*N
    for i in range(N):
        x[i],y[i] = map(int, input().split())
    if x==y:
        return 0
    for i in range(N):
        ans += x[i]
        if x[i]>y[i]:
            miny = min(miny,y[i])
    ans -= miny
    return ans
print(solve())