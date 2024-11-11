def resolve():
    def Dijkstra(s, g):
        from collections import deque
        d = {s}
        queue = deque()
        for q in edge[s]:
            queue.append((1, q))
        while queue:
            dist, point = queue.popleft()
            if point in d:
                continue
            d.add(point)
            if point == g:
                return dist
            for nextp in edge[point]:
                if not nextp in d:
                    if not -1 in point or -1 in nextp:
                        queue.appendleft((dist, nextp))
                    else:
                        queue.append((dist + 1, nextp))
        return -1
    import sys
    input = sys.stdin.readline
    from collections import defaultdict
    n, m = map(int, input().split())
    edge = defaultdict(set)
    for _ in range(m):
        p, q, c = map(int, input().split())
        p, q = p - 1, q - 1
        edge[(p, c)].add((q, c))
        edge[(q, c)].add((p, c))
        edge[(p, c)].add((p, -1))
        edge[(q, c)].add((q, -1))
        edge[(p, -1)].add((p, c))
        edge[(q, -1)].add((q, c))
    print(Dijkstra((0, -1), (n - 1, -1)))


if __name__ == '__main__':
    resolve()
