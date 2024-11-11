n,m = [int(a_temp) for a_temp in input().strip().split()]
p = []
for i in range(m):
    p.append([int(a_temp) for a_temp in input().strip().split()])
for i in range(m):
    traitor = True
    d = {}
    for e in p[i][1:]:
        d[e]=True
        if -1*e in d:
            traitor=False
            break
    if traitor:
        print("YES")
        break
if not traitor:
    print("NO")