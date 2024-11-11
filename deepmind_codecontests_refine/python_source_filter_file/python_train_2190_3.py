from collections import defaultdict

vertice,edge = map(int,input().split(" "))
cost = [[0 if m == n else float("inf") for n in range(vertice)] for m in range(vertice)]
link = defaultdict(dict)
weight = defaultdict(dict)

for e in range(edge):
    i,j,w = map(int,input().split(""))
    link[i] = link.get(i,set()) | {j}
    weight[i].update({j:w})

vertice_cnt = 0
while 1:
    if vertice_cnt >= vertice:
        print("NEGATIVE CYCLE")
        break
    update = False
    for source in range(vertice):
        for k,value in link.items():
            for v in value:
                if cost[source][v] > cost[source][k] + weight[k][v]:
                    cost[source][v] = cost[source][k] + weight[k][v]
                    update = True
    if not update:
        for o in range(vertice):

            print(*([n if n != float("INF") else "INF" for n in cost[o]]))
        break
    vertice_cnt += 1