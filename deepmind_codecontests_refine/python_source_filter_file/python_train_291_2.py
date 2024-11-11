def resolve():

    N,M = map(int,input().split())
    root = list(range(N))
    depth = [1 for _ in range(N)]
    dist = [0 for _ in range(N)]

    def find(a,root,dist):
        if root[a] == a:
            return (a,0)
        else:
            root[a],d = find(root[a],root,dist)
            dist[a] += d
            return(root[a],dist[a])

    def unite(a,b,d,root,depth,dist):
        A,dist_a = find(a,root,dist)
        B,dist_b = find(b,root,dist)

        if A == B:
            if dist_b - dist_a == d:
                return True
            else:
                return False
        else:
            if depth[A] > depth[B]:
                root[B] = A
                depth[A] += depth[B]
                dist[B] = dist_a - dist_b + d
            else:
                root[A] = B
                depth[B] += depth[A]
                dist[A] = dist_a - dist_b - d
            return True
        
    ans = True
    for _ in range(M):
        L,R,D = map(int,input().split())
        if not (unite(L-1,R-1,D,root,depth,dist)):
            ans = False
            break
    print("Yes" if ans else "No")
resolve()