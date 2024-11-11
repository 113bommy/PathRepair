def main():
    n,m = map(int,input().split())
    M = {}
    for i in range(n):
        M[i+1] = []
    for _ in range(m):
        a,b = map(int,input().split())
        M[a] += [b]
        M[b] += [a]
    G = [0 for _ in range(n)]
    g = 0
    for i in range(n):
        if G[i] == 0:
            g+=1
            G[i] = g
            que = [i+1]
            while len(que)>0:
                q = que.pop(0)
                for nv in M[q]:
                    if G[nv-1] != 0:
                        continue
                    G[nv-1] = g
                    que.append(nv)
    print(max(G)-1)

if __name__ == "__main__":
    main()
