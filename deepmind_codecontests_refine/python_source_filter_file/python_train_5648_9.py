import heapq
t = int(input())
for _ in range(t):
    n = int(input())
    a = [0] * n
    heap = [(-n, 0)]
    action = 1
    while heap:
        length, left = heapq.heappop(heap)
        length = -length
        right = left + length - 1
        mid = (left + right) // 2
        a[mid] = action
        if mid > left:
            heapq.heappush(heap, (-1 * (mid - left), left))
        if mid < right:
            heapq.heappush(heap, (-1 * (right - mid), mid + 1))
        action += 1
    print(a)