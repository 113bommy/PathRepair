from collections import defaultdict

def red(lis,left=True):
    while len(lis)>1:
        v1 = lis.pop()
        v2 = lis.pop()
        cost = (v1+v2)//2 if left else (2*m-v1-v2)//2
        ans[v1],ans[v2]=cost,cost
    return lis

def start(ini,di):
    for i in range(n):
        val,curr = l[i],d[i]
        if val % 2 != ini: continue
        if curr=="L":
            if di["R"]:
                pos =di["R"].pop()
                cost = (val-pos)//2
                ans[pos],ans[val]=cost,cost
            else:
                di["L"].append(val)
        else:
            di["R"].append(val)
    di["L"] = red(di["L"][::-1])
    di["R"] = red(di["R"][::-1],False)
    if di["L"] and di["R"]:
        v1 = di["L"].pop()
        v2 = di["R"].pop()
        cost = (m + (m-v2)+v1)//2
        ans[v1],ans[v2]=cost,cost

for _ in range(int(input())):
    n,m = map(int,input().split())
    initial = list(map(int,input().split()))
    l,d = zip(*sorted(zip(initial,input().split())))
    ans = defaultdict(lambda :-1)
    evens = defaultdict(list)
    odds = defaultdict(list)
    start(0,evens)
    start(1,odds)
    for i in range(n):
        initial[i] = ans[initial[i]]
    print(*initial)