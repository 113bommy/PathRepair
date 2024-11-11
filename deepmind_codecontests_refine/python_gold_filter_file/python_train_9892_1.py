n = int(input())
pre = list(map(int, input().split()))
ino = list(map(int, input().split()))

d = []
root = pre[0]
pre = iter(pre).__next__

def dfs(l, r):
    global d
    if l >= r:
        return
    c = pre()
    m = ino.index(c)
    dfs(l, m)
    dfs(m+1, r)
    d += [c]
    
dfs(0, len(ino))
print(*d)

