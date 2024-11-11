import sys
sys.setrecursionlimit(100000)

N = int(input())
vertex = set()
conn = [[] for _ in range(2*10**5 + 1)]
check = [False]*(2*10**5 + 1)
for i in range(N):
    x, y = [int(x) for x in input().split()]
    vertex.add(x)
    vertex.add(y + 10**5)
    conn[x].append(y + 10**5)
    conn[y + 10**5].append(x)

count = [0] * 2
def dfs(z):
    if check[z] == True:
        return
    check[z] = True
    if z <= 10**5:
        count[0] += 1
    else:
        count[1] += 1
    for w in conn[z]:
        dfs(w)

ans = 0
for z in vertex:
    if check[z] == False:
        count = [0]*2
        dfs(z)
        X, Y = count[0], count[1]
        ans += X * Y
ans -= N

print(ans)