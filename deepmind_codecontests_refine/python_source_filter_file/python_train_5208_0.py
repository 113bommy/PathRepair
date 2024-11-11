class FordFulkerson:
    """Ford-Fulkerson Algorithm: find max-flow
       complexity: O(FE) (F: max flow)
    """
    def __init__(self, V, E, source, sink):
        """ V: the number of vertexes
            E: adjacency list
            source: start point
            sink: goal point
        """
        self.V = V
        self.E = [[] for _ in range(V)]
        for fr in range(V):
            for to, cap in E[fr]:
                self.E[fr].append([to, cap, len(self.E[to])])
                self.E[to].append([fr, 0, len(self.E[fr])-1])
        self.maxflow = self.ford_fulkerson(source, sink)

    def ford_fulkerson(self, source, sink, INF=10**9):
        """find max-flow"""
        def dfs(vertex, sink, flow):
            """find augmenting path"""
            if vertex == sink:
                return flow
            used[vertex] = True
            for i, (to, cap, rev) in enumerate(self.E[vertex]):
                if not used[to] and cap > 0:
                    d = dfs(to, sink, min(flow, cap))
                    if d > 0:
                        self.E[vertex][i][1] -= d
                        self.E[to][rev][1] += d
                        return d
            return 0

        maxflow = 0
        while True:
            used = [False] * self.V
            flow = dfs(source, sink, INF)
            if flow == 0:
                return maxflow
            else:
                maxflow += flow

V, E = map(int, input().split())
edge = [[] for _ in range(E)]
for _ in range(E):
    u, v, cap = map(int, input().split())
    edge[u].append((v, cap))
print(FordFulkerson(V, edge, 0, V-1).maxflow)