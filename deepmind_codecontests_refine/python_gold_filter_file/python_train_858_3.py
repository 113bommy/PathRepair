import sys, threading
from sys import stdin, stdout

sys.setrecursionlimit(10 ** 9)
threading.stack_size(16 * 2048 * 2048)

graph = []
centroids = []
size = []
n = 0


def dfs(vertex, parent):
    size[vertex] = 1
    is_centroid = True
    edge = (parent, vertex)

    for adj in graph[vertex]:
        if adj != parent:
            last_edge = dfs(adj, vertex)
            size[vertex] += size[adj]
            edge = last_edge

            if size[adj] > n / 2:
                is_centroid = False

    if n - size[vertex] > n / 2:
        is_centroid = False
    if is_centroid:
        centroids.append([vertex, *last_edge])

    return edge


def compute_centroids():
    global size
    size = [0] * len(graph)
    global centroids
    centroids = []
    global n
    n = len(graph) - 1

    dfs(1, -1)

    return centroids


# a graph is represented as a list of adj for each vertex, graph[i] return a list of i adjacents
def link_cut_centroids(g):
    global graph
    graph = g

    if len(graph) % 2 == 0:
        stdout.write("{} {}\n".format(1, graph[1][0]))
        stdout.write("{} {}\n".format(1, graph[1][0]))

    else:
        ans = compute_centroids()
        if len(ans) == 1:
            stdout.write("{} {}\n".format(ans[0][1], ans[0][2]))
            stdout.write("{} {}\n".format(ans[0][1], ans[0][2]))
        elif len(ans) == 2:
            stdout.write("{} {}\n".format(ans[0][1], ans[0][2]))
            stdout.write("{} {}\n".format(ans[0][2], ans[1][0]))


def main_method():
    # Reading input
    # INPUT
    # line1: t number of test cases(1<=t<=10^4)
    # foreach t:
    # line 1: n number of vertexs((1<=n<=10^5))
    # line 1-n: x, y edge between x and y

    t = int(stdin.readline())
    # t = int(input())

    for _ in range(t):
        # n = int(input())
        n = int(stdin.readline())
        g = [0] * (n + 1)
        for i in range(n - 1):
            # x, y = map(int, input().split())
            x, y = map(int, stdin.readline().split())
            try:
                g[x].append(y)
            except:
                g[x] = [y]
            try:
                g[y].append(x)
            except:
                g[y] = [x]
        link_cut_centroids(g)


threading.Thread(target=main_method).start()
