import heapq

N = int(input())
a_list = list(map(int, input().split()))

max_score = - float("inf")

red_list = a_list[:N]
blue_list = [-a for a in a_list[2 * N:]]
heapq.heapify(red_list)
heapq.heapify(blue_list)
red_sum = [sum(red_list)]
blue_sum = [sum(blue_list)]

for i in range(N, 2 * N):
    heapq.heappush(red_list, a_list[i])
    item = heapq.heappop(red_list)
    red_sum.append(max(red_sum[-1], red_sum[-1] + a_list[i] - item))

for i in range(2 * N - 1, N - 1, -1):
    heapq.heappush(blue_list, -a_list[i])
    item = heapq.heappop(blue_list)
    blue_sum.append(max(blue_sum[-1], blue_sum[-1] - a_list[i] - item))
for i in range(N):
    score = red_sum[i] + blue_sum[-(i + 1)]
    if max_score < score:
        max_score = score
print(max_score)
