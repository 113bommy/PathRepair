from collections import defaultdict
import heapq

T = int(input())
for _ in range(T):
    N, A, B = [int(x) for x in input().split(' ')]
    b = [int(x) for x in input().split(' ')]
    a = [0 for _ in range(N)]

    split = defaultdict(list)
    for i, x in enumerate(b):
        split[x].append((i, x))
    heap = []
    for x in split.values():
        heapq.heappush(heap, (-len(x), x))
    for _ in range(A):
        _, cur = heapq.heappop(heap)
        i, x = cur.pop()
        a[i] = x
        if len(cur):
            heapq.heappush(heap, (-len(cur), cur))
    
    if heap:
        rot = -heap[0][0]
        rem = [x for cur in heap for x in cur[1]]
        d = N - B
        if 2*(rot-d) > len(rem):
            print('NO')
            continue
        heap[0] = (heap[0][0] + d, heap[0][1])
        rot = -min(x[0] for x in heap)
        unused = list(set(range(1, N+2))-set(b))[0]
        #print(rem, rot)
        for i in range(d):
            rem[i] = (rem[i][0], unused)
        
        #print(rem)
        for i in range(len(rem)):
            a[rem[i][0]] = rem[(i-rot+len(rem))%len(rem)][1]
    print('YES')
    print(' '.join(str(x) for x in a))