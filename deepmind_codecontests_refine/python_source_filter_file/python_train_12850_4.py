from collections import *
from sys import setrecursionlimit, stdin
import threading

mod = 1000000007


def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return list(stdin.readline()[:-1])


def main():
    class graph:
        # initialize graph
        def __init__(self, gdict=None):
            if gdict is None:
                gdict = defaultdict(list)
            self.gdict, self.edges, self.l = gdict, [], defaultdict(int)

        # add edge
        def addEdge(self, node1, node2, w=None):
            if w != None:
                self.gdict[node1].append([node2, w])
                self.gdict[node2].append([node1, w])
            else:
                self.gdict[node1].append(node2)
                # self.gdict[node2].append(node1)
            self.edges.append([node1, node2, w])
            self.l[node1] += 1
            self.l[node2] += 1

        def scc_utils(self, v):

            # initilaize time and disc
            self.disc[v], self.low[v], self.stack[v] = self.time, self.time, 1
            self.time += 1
            self.st.append(v)

            # loop edges
            for i in self.gdict[v]:
                if self.disc[i] == -1:
                    self.scc_utils(i)
                    self.low[v] = min(self.low[v], self.low[i])

                elif self.stack[i]:
                    self.low[v] = min(self.low[v], self.disc[i])

                # print founded scc
            if self.low[v] == self.disc[v]:
                node, mem = -1, defaultdict(int)
                while node != v:
                    node = self.st.pop()
                    # print(node, end=' ')
                    self.stack[node] = 0
                    mem[cost[node - 1]] += 1
                # print(end='\n')

                self.count += min(mem)
                self.mi = ((self.mi % mod) * (mem[min(mem)] % mod)) % mod

        def scc(self, n):
            self.time, self.count, self.mi = 0, 0, 1
            self.disc, self.low, self.stack, self.st = [-1] * (n + 1), [-1] * (n + 1), [0] * (n + 1), []
            for i in range(1, n + 1):
                if self.disc[i] == -1:
                    self.scc_utils(i)

            print(self.count, self.mi)

    n, cost, m, g = int(input()), arr_inp(1), int(input()), graph()
    for i in range(m):
        u, v = arr_inp(1)
        g.addEdge(u, v)
    g.scc(n)


if __name__ == '__main__':
    setrecursionlimit(100000)
    threading.stack_size(10240000)
    thread = threading.Thread(target=main)
    thread.start()
