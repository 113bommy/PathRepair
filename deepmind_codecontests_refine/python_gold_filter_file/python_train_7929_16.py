n = int(input())
nlist = set(map(int, input().split()))
m = int(input())
mlist = set(map(int, input().split()))

for n in nlist:
    for m in mlist:
        a = m + n
        if a in nlist or a in mlist:
            continue
        else:
            print(n, m)
            exit(0)
