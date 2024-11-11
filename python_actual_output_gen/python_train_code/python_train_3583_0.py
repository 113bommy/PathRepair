nt = int(input())
for _ in range(nt):
    n = int(input())
    inexps = sorted(map(int, input().split()))
    c = grps = 0
    for i in inexps:
        c += 1
        if c >= i:
            c = 0
            grps += 1
        print(grps)