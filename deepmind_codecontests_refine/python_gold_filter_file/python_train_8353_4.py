from collections import deque
import collections

def solve (n, k, s):
    lettersCounter = collections.Counter(s)
    for m in range(n, 0, -1):
        used = [False]*m
        cycles = deque()
        for i in range(m):
            if used[i]:
                continue
            j = (i + k)%m
            used[i] = True
            cycles.insert(len(cycles), 1)
            while not used[j]:
                cycles[len(cycles) - 1]+=1
                used[j] = True
                j = (j + k)%m

        cycles = list(sorted(cycles))
        count = list(sorted(lettersCounter.values()))
        canDoIt = True

        while cycles:
            if count[len(count) - 1] < cycles[len(cycles) - 1]:
                canDoIt = False
                break
            else:
                count[len(count) - 1] -= cycles[len(cycles) - 1]
                cycles.pop()
                count = sorted(count)

        if canDoIt:
            return m


t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()
    print(solve(n, k, s))