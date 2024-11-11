from collections import defaultdict
import sys
try:
    sys.setrecursionlimit(10**6)
    n = int(input())
    connections = [0,0]+list(map(int, input().split()))
    sums = list(map(int, input().split()))
    values = [0 for _ in range(len(sums))]
    unknown = set()
    tree = defaultdict(list)
    for i, (connect, curSum) in enumerate(zip(connections[1:], sums)):
        if curSum == -1:
            sums[i] = sums[connections[connect]]
            unknown.add(i+1)
            values[i] = 0
        else:
            if i == 0:
                values[0] = sums[0]
                continue
            value = sums[i]-sums[connections[connect]-1]
            if value < 0:
                print(-1)
                exit()
            values[i] = value
        tree[connect].append(i+1)

    total = [sum(values)]
    connections = 0
    sums = 0
    for i in range(1,n+1):
        mn = float("inf")
        if i not in tree:
            continue
        if i in unknown:
            for v in tree[i]:
                if values[v-1] < mn:
                    mn = values[v-1]
            total[0] += mn - mn*len(tree[i])

    print(total[0])
except Exception as e:
    print(e)

