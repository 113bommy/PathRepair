from collections import defaultdict

v_num, e_num, flow = (int(n) for n in input().split(" "))
edges = defaultdict(list)
for _ in range(e_num):
    s1, t1, cap, cost = (int(n) for n in input().split(" "))
    edges[s1].append([t1, cap, cost, len(edges[t1])])
    edges[t1].append([s1, cap, cost, len(edges[s1]) - 1])
answer = 0
before_vertice = [float("inf") for n in range(v_num)]
before_edge = [float("inf") for n in range(v_num)]
sink = v_num - 1
while True:
    distance = [float("inf") for n in range(v_num)]
    distance[0] = 0
    updated = 1
    while updated:
        updated = 0
        for v in range(v_num):
            if distance[v] == float("inf"):
                continue
            for i, (target, cap, cost, trace_i) in enumerate(edges[v]):
                if cap > 0 and distance[target] > distance[v] + cost:
                    distance[target] = distance[v] + cost
                    before_vertice[target] = v
                    before_edge[target] = i
                    updated = 1
    if distance[sink] == float("inf"):
        print(-1)
        break
    decreased = flow
    trace_i = sink
    while trace_i != 0:
        decreased = min(decreased, edges[before_vertice[trace_i]][before_edge[trace_i]][1])
        trace_i = before_vertice[trace_i]
    flow -= decreased
    trace_i = sink
    while trace_i != 0:
        this_edge = edges[before_vertice[trace_i]][before_edge[trace_i]]
        this_edge[1] -= decreased
        answer += this_edge[2] * decreased
        edges[trace_i][this_edge[3]][1] += decreased
        trace_i = before_vertice[trace_i]
    if flow <= 0:
        print(answer)
        break