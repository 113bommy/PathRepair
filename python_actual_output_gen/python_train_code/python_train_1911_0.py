while True:
    n = int(input())
    m = int(input())
    if n==0: break
    tab = [[] for _ in range(n)]
    for _ in range(m):
        a,b = map(int,input().split())
        a -= 1
        b -= 1
        tab[a].append(b)
        tab[b].append(a)
    ans = set(tab[0])
    foff = set()
    for i in ans:
        foff = foff | set(tab[i])
    print(len((ans|foff)-{1}))