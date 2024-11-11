n = int(input())
vs = [[] for i in range(n)]
out = [0]*n

for i in range(n-1):
    a, b = [int(i) for i in input().split()]
    vs[a].append([b,i+1])
    vs[b].append([a,i+1])

nex = [[0,-1]]

def coloring(index,defColor):
    i=0
    for v in vs[index]:
        if i==defColor:
           i+=1
        out[v[1]]=i
        vs[v[0]].remove([index,v[1]])
        nex.append([v[0],i])
        i+=1
    out[0] = max(out[0],i-1)

while nex.__len__()>0:
    c,d = nex.pop()
    coloring(c,d)

for i in range(n):
    print(out[i]+1)



