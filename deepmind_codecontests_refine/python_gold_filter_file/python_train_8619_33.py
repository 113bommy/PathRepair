import sys
from heapq import heappush, heappop
input = sys.stdin.readline

num, person = map(int, input().split())
arr = []

for i in range(num):
    s, t, x = map(int, input().split())
    arr.append((s - x - 0.5, 1, x, i))
    arr.append((t - x - 0.5, 0, x, i))

for i in range(person):
    d = int(input())
    arr.append((d,))

arr.sort()

heap = []
done = set()

for elem in arr:
    if len(elem) == 1:
        while heap and heap[0][1] in done:
            heappop(heap)
        if heap:
            print(heap[0][0])
        else:
            print(-1)
        continue

    time, kind, x, i = elem
    if kind:
        heappush(heap, (x, i))
    else:
        done.add(i)
