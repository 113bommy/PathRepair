from sys import stdin, stdout
def readLine_int_list():return list(map(int, stdin.readline().split()))

def find(x):
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]
        
def unite(x,y):
    x = find(x)
    y = find(y)
    
    if x==y: return
    if rank[x]<rank[y]:
        par[x] = y
    else:
        par[y] = x
        if rank[x] == rank[y]:
            rank[x]+=1
            
def same(x,y):
    return find(x)==find(y)
    
n,m = readLine_int_list()
v = n + m
par = [i for i in range(0, v)]
rank = [1] * v
def main():
    for i in range(n):
        for ii in readLine_int_list()[1:]:
           unite(i, ii)
           
    r = "YES"
    for i in range(0, n):
        if find(i) != find(0):
            r = "NO"
    print(r)
    
if __name__ == '__main__':
    main()