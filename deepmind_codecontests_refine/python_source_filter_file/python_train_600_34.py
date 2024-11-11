import sys
from heapq import heapify, heappush, heappop
read = sys.stdin.read


def main():
    N, M, *LRC = map(int, read().split())
    graph = [[(0, i - 1)] for i in range(N + 1)]
    graph[1] = []

    for L, R, C in zip(*[iter(LRC)] * 3):
        graph[L].append((C, R))

    distance = [-1] * (N + 1)
    queue = []
    heapify(queue)
    heappush(queue, (0, 1))

    while queue:
        cost, node = heappop(queue)
        if distance[node] == -1:
            distance[node] = cost
            for add_cost, next_node in graph[node]:
                if distance[next_node] == -1:
                    heappush(queue, (cost + add_cost, next_node))

    print(distance)


if __name__ == '__main__':
    main()