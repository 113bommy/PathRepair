import sys
import queue

T = int(sys.stdin.readline())
adj_list = dict()
ids = []
for _ in range(T):
    line = sys.stdin.readline().split()
    cond = int(line[0])

    # forms the interval (x, y) x < y
    x = int(line[1])
    y = int(line[2])

    # check if this is a new interval or a query 
    if cond == 1:
        new_interval = (x, y)
        ids.append(new_interval)
        adj_list[new_interval] = set()
        for interval, neighbors in adj_list.items():
            # new interval surrounds other interval
            if x <= interval[0] and y >= interval[1]:
                neighbors.add(new_interval)
            # new interval inside other interval
            elif x >= interval[0] and y <= interval[1]:
                adj_list[new_interval].add(interval)
            # overlapping intervals
            elif (x > interval[0] and x < interval[1]) or (y > interval[0] and y < interval[1]):
                neighbors.add(new_interval)
                adj_list[new_interval].add(interval)
    elif cond == 2:
        target = ids[y-1]
        visited = set()
        bfs = queue.Queue()
        bfs.put(ids[x-1])
        while not bfs.empty():
            interval = bfs.get()

            if interval in visited:
                continue
            visited.add(interval)

            if interval == target:
                bfs.put((-1, -1))
                break

            for neighbor in adj_list[interval]:
                bfs.put(neighbor)
        if bfs.empty():
            print('NO')
        else:
            print('YES')

