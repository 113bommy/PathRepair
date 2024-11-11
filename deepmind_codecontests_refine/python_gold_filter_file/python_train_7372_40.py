D, G = map(int, input().split())
PC = [0]+[list(map(int,input().split())) for _ in range(D)]

def dfs(d, g):
    if(d == 0):
        return 1e9

    c = min(g//(100*d), PC[d][0])
    s = 100*d*c
    if c == PC[d][0]:
        s += PC[d][1]
    if s<g:
        c += dfs(d-1, g-s)
    return min(c, dfs(d-1,g))

print(dfs(D, G))