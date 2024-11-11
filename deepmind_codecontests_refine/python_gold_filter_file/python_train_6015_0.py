import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

class SCC:
    def __init__(self, n):
        self.n = n
        self.graph = [[] for _ in range(n)]
        self.graph_rev = [[] for _ in range(n)]
        self.already = [False]*n
    
    def add_edge(self, fr, to):
        if fr == to:
            return
        self.graph[fr].append(to)
        self.graph_rev[to].append(fr)
    
    def dfs(self, node, graph):
        self.already[node] = True
        for n in graph[node]:
            if self.already[n]:
                continue
            self.dfs(n, graph)
        self.order.append(node)
    
    def first_dfs(self):
        self.already = [False]*self.n
        self.order = []
        for i in range(self.n):
            if self.already[i] == False:
                self.dfs(i, self.graph)
    
    def second_dfs(self):
        self.already = [False]*self.n
        self.ans = []
        for n in reversed(self.order):
            if self.already[n]:
                continue
            self.already[n] = True
            self.order = []
            self.dfs(n, self.graph_rev)
            self.order.reverse()
            self.ans.append(self.order)

    def scc(self):
        self.first_dfs()
        self.second_dfs()
        return self.ans


def main():
    n, m = map(int, input().split())
    scc = SCC(n)

    for i in range(m):
        a, b = map(int, input().split())
        scc.add_edge(a, b)
    
    scc_list = scc.scc()

    print(len(scc_list))
    for s in scc_list:
        print(len(s), end=" ")
        print(*s)

    
if __name__ == "__main__":
    main()