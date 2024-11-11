N,M = map(int,input().split())
par = [0]+[-1 for i in range(N)]

def find(x):
    if par[x] == -1:
        return x
    else:
        par[x] = find(par[x]) #経路圧縮
        return par[x]

def same(x,y):
    return find(x) == find(y)
  
def unite(x,y):
    x = find(x)
    y = find(y)
    if x == y:
        return 0
    par[x] = y
    
for i in range(M):
    a,b = map(int,input().split())
    unite(a,b)
print(len([i for i in par if i == -1]))