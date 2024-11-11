from collections import defaultdict


def bfs(start, end):
    seen = set()
    steps = defaultdict()

    neighbors = [start]
    steps[start] = 0
    while neighbors:
        current = neighbors.pop(0)
        if current == end:
            return steps[current]
        elif current < 0:
            continue
        elif current not in seen:
            seen.add(current)
            neighbors.append(current - 1)
            steps[current - 1] = steps[current] + 1
            if current < end:
                neighbors.append(current * 2)
                steps[current * 2] = steps[current] + 1

    return -1


n, m = map(int, input().split())
if m < n:
    print(n - m)
else:
    print(bfs(n, m))
