import sys
sys.setrecursionlimit(10 ** 9)

n, m = map(int, input().split())
root = [-1] * n
def find(x):
    if root[x] < 0:
        return x
    else:
        root[x] = find(x)
        return root[x]
    

def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    root[x] += root[y]
    root[y] = x
        

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    unite(a, b)

ans = len([i for i in root if i < 0]) - 1
print(ans)

