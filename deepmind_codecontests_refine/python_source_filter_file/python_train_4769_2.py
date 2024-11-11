import heapq

Q = int(input())
b_sum = 0
a_list = []
left = []
right = []
res = 0

for i in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        b_sum += query[2]
        if len(right) == 0:
            a = query[1]
            heapq.heappush(right, -a)
        else:
            res += abs(query[1] + right[0])
            if query[1] <= -right[0]:
                heapq.heappush(right, -query[1])
            else:
                heapq.heappush(left, query[1])
        if len(right) < len(left):
            x = heapq.heappop(left)
            y = -right[0]
            res += abs(y - x)
            heapq.heappush(right, -x)
        elif len(right) > len(left) + 1:
            x = - heapq.heappop(right)
            heapq.heappush(left, x)
    else:
        print(-right[0], res + b_sum)
