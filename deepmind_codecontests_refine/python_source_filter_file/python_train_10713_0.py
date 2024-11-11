from collections import defaultdict

class Edge:
    def __init__(self, inputs):
        start, end, self.dist = [ int(i) for i in inputs ]
        self.nodes = [start, end]

    def isConnect(self, node):
        return node in self.nodes

    def other_side(self, node):
        if self.nodes[0] == node:
            return self.nodes[1]
        else:
            return self.nodes[0]

    def __str__(self):
        return "%d - %d (%d)" % (self.nodes[0], self.nodes[1], self.dist)

def calc_cost(list, tickets):
    s_list = sorted( list, reverse=True )
    return sum( c / t for c, t in zip(s_list, tickets) )

while True:
    n, m, p, a, b = [ int(i) for i in input().split() ]

    print("ticktes: %d, m: %d, edge_num: %d, %d -> %d)" % (n, m, p, a, b))

    if n == m == p == a == b == 0:
        quit()

    tickets = sorted( [int(i) for i in input().split()] , reverse=True)

    e = defaultdict(list)

    for i in range(p):
        start, end, cost = [ int(i) for i in input().split() ]
        e[start].append((end, cost))
        e[end].append((start, cost))

    m_cost = defaultdict(lambda: float('inf'))

    # edges = [ Edge(input().split()) for i in range(p) ]

    # print(tickets)

    result = (a, [a], [], float('inf'))

    if p == 0:
        print("Impossible")
        continue

    q = [ (e[0], [a, e[0]], [e[1]], calc_cost([e[1]], tickets)) for e in e[a] ]

    while len(q) != 0:
        now = q.pop()

        # print("now: ", now)

        # ?????±????????°????¶?????????´???
        if len(now[1]) - 1 > n:
            continue

        if m_cost[now[0]] < now[3]:
            continue
        else:
            m_cost[now[0]] = now[3]


        # ??????????????????????????£?????´???
        if now[0] == b and now[3] < result[3]:
            result = now

        q.extend([ (e[0], now[1] + [e[0]], now[2] + [e[1]],  calc_cost(now[2] + [e[1]], tickets))
            for e in e[now[0]] if e[0] not in now[1] ])

    if result[0] == b:
        print(result[3])
    else:
        print("Impossible")