from collections import deque


def solve(p, s):
    children = {}
    parents = {}
    for i, e in enumerate(p):
        if e not in children:
            children[e] = []
        children[e].append(i+2)
        parents[i+2] = e

    sums = {}
    for i, e in enumerate(s):
        sums[i+1] = e if e != -1 else None

    queue = deque([1])

    while len(queue) > 0:
        to_visit = queue.popleft()
        if to_visit in children:
            for child in children[to_visit]:
                queue.append(child)

        if sums[to_visit] is None:
            parent = sums[parents[to_visit]]
            if to_visit in children:
                min_child = min(map(lambda x: sums[x], children[to_visit]))
                if min_child - parent < 0:
                    return -1
                sums[to_visit] = min_child
            else:
                sums[to_visit] = parent

    result = 0

    for key in sums:
        if key in parents:
            result += sums[key] - sums[parents[key]]
        else:
            result += sums[key]

    return result






if __name__ == "__main__":
    n = int(input())
    p = map(int, input().split())
    s = map(int, input().split())
    print(solve(p, s))