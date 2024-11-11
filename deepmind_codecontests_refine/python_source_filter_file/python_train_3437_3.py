from collections import defaultdict
import heapq
v_num = int(input())
connect = defaultdict(list)

for _ in range(v_num):
    que = [int(n) for n in input().split(" ")]
    connect[que[0]] = [[v, w] for v, w in zip(que[2:len(que):2], que[3:len(que):2])
    # weight_edge[que[0]] = {k:v for k, v in zip(que[2:len(que):2], que[3:len(que):2])}
queue = []
heapq.heapify(queue)
heapq.heappush(queue, [0, 0])
distance = [-1 for n in range(v_num)]
went = 0
visited = set()
while went < v_num:
    q = heapq.heappop(queue)
    weight, here = q
    if here in visited:
        continue
    visited |= {here}
    went += 1
    distance[here] = weight
    for conn in connect[here]:
        if conn[0] not in visited:
            heapq.heappush(queue, [weight + conn[1], conn[0]])
for i in range(v_num):
    print(i, distance[i])