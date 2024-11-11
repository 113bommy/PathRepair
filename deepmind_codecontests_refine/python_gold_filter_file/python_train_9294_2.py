import collections
n = int(input())
a = list(map(int, input().split()))

def lowbit(x):
    return x & -x
    
def add(x, k):
    while x <= n:
        tree[x] = max(tree[x], k)
        x += lowbit(x)
        
def query(x):
    ans = 0
    while x > 0:
        ans = max(ans, tree[x])
        x -= lowbit(x)
    return ans
    
G = collections.defaultdict(list)
tree = collections.defaultdict(int)
for i in range(1, n + 2):
    G[i].append(0)
for i in range(1, n + 1):
    G[a[i - 1]].append(i)
for i in range(1, n + 2):
    G[i].append(n + 1)
ans = 1
for i in range(1, n + 2):
    flag, sz = 0, len(G[i])
    if sz == n + 2:
        ans = i
        break
    for j in range(1, sz):
        f = query(G[i][j - 1] + 1)
        if f < G[i][j]:
            flag = 1
    if not flag:
        break
    for j in range(1, sz):
        f = G[i][j - 1] + 1
        add(f, G[i][j])
    ans = i + 1
print(ans)