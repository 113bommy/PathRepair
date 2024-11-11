#import sys
from heapq import heapify, heappushpop
from heapq import _heapify_max as heapify_max, _siftup_max


def heappushpop_max(heap, item):
    if heap and heap[0] > item:
        item, heap[0] = heap[0], item
        _siftup_max(heap, 0)
    return item


fin = sys.stdin.readline
N, *a_list = map(int, open(0).read().split())

left_pq = a_list[:N]
right_pq = a_list[2 * N:]
heapify(left_pq)
heapify_max(right_pq)

left_sum = [sum(left_pq)]
right_sum = [sum(right_pq)]
for k in range(N, 2 * N):
    left_item = a_list[k]
    right_item = a_list[-k - 1]
    left_sum.append(left_sum[-1] - heappushpop(left_pq, left_item) + left_item)
    right_sum.append(right_sum[-1] - heappushpop_max(right_pq, right_item) + right_item)

max_sum = max(map(sum, zip(left_sum, [-item for item in right_sum[::-1]])))
print(max_sum)
