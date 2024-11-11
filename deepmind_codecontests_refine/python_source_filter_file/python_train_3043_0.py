

t = int(input())
for _ in range(t):
    n,d = map(int,input().split())

    dsum = n*(n-1)//2

    if d>dsum: 
        print("NO")
        continue

    tree = [[i] for i in range(n)]

    lmin = 1
    while dsum > d:
        l = len(tree)-1
        while dsum > d and l>lmin:
            l -= 1
            dsum -= 1

        if l == len(tree)-1:
            break

        node = tree[-1][-1]
        tree[-1].pop()
        if not tree[-1]:
            tree.pop()
        tree[l].append(node)
        if len(tree[l])==2**l:
            lmin += 1

    
    if dsum > d:
        print("NO")
        continue
    
    print("YES")
    parent = [0]*(n-1)
    for j in range(1,len(tree)):
        layer = tree[j]
        for i in range(len(layer)):
            node = layer[i]
            parent[node-1] = tree[j-1][i//2]

    print(*parent)
    
