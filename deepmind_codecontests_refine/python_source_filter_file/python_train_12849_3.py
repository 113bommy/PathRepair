n, m = map(int, input().split())
steps = set()
flg = True
for i in range(n):
    arr = list(input())
    if flg:
        sidx = arr.index('S')
        gidx = arr.index('G')
        if gidx > sidx:
            flg = False
            break
        else:
            steps.add(sidx - gidx)
if not flg:
    print(0)
else:
    print(len(steps))
