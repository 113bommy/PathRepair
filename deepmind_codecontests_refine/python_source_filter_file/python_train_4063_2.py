def root(x,rt):
    if rt[x] == x:
        return x
    else:
        while rt[x] != x:
            rt[x] = root(rt[x],rt)
            return rt[x]
def union(x,y,rt,rank):
    rootx = root(x,rt)
    rooty = root(y,rt)
    if rootx == rooty:
        return 0
    else:
        if rank[rootx] < rank[rooty]:
            rt[rooty] = rootx
        else:
            rt[rootx] = rooty
            if rank[rootx] == rank[rooty]:
                rank[rootx] += 1

def issame(x,y,rt):
    return root(x,rt) == root(y,rt)

length,query = (int(n) for n in input().split(" "))
rootlist = [n for n in range(length)]
rank = [0 for n in range(length)]

for q in range(query):
    #print(root)
    com,x,y = (int(n) for n in input().split(" "))
    if com == 0:
        union(x,y,rootlist,rank)
    else:
        print(1 if issame(x,y,rootlist) else 0)