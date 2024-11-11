N,A,B,C = map(int, input().split())
 
bms = [int(input()) for _ in Range(N)]
 
def dfs(cur,a,b,c):
    if cur == N:
        s = abs(A-a)+abs(B-b)+abs(C-c)-30 if min(a,b,c) > 0 else 10**9
        return s
    s_0 = dfs(cur+1,a,b,c)
    s_a = dfs(cur+1,a+bms[cur],b,c) + 10
    s_b = dfs(cur+1,a,b+bms[cur],c) + 10
    s_c = dfs(cur+1,a,b,c+bms[cur]) + 10
    return min(s_0,s_a,s_b,s_c)

print(dfs(0,0,0,0))