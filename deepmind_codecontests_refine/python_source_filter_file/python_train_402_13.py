import operator
for e in iter(input,'0'):
    target = [[*map(int,input().split())]for _ in[0]*int(e)]
    s,t = min(target)
    target = {(x - bx, y - by) for x, y in target}
    max_tx = max(map(lambda x:x[0], target))
    b = {tuple(map(int,input().split()))for _ in[0]*int(input())}
    max_sx = max(map(operator.itemgetter(0), b))
    lim_x = max_sx - max_tx
    for x,y in b:
        if x > lim_x:continue
        for u,v in target:
            if (x + u, y + v) not in b:break
        else:
            print(x - bx, y - by)
            break
