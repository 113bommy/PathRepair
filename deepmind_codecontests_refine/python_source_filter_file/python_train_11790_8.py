t = int(input())
for _ in range(t):
    n = int(input())
    married = [False for _ in range(n)]
    gs = [[] for _ in range(n)]
    for i in range(n):
        ks = list(map(int, input().split()))[1:]
        for k in ks:
            gs[i].append(k-1)
    d = -1
    for i, g in enumerate(gs):
        for gi in g:
            if not married[gi]:
                married[i] = True
                break
        else:
            d = i

    if all(married):
        print('OPTIMAL')
    else:
        print('IMPROVE')
        for i, m in enumerate(married):
            if not m:
                print(d+1, i+1)
                break