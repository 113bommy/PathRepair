import heapq

input()
heap = [int(i) for i in input().split()]
heapq.heapify(heap)

cost = 0

while len(heap) > 1:
    amountToMerge = 3
    if len(heap) in [2, 4]:
        amountToMerge = 2

    mergedPileSize = 0
    for _ in range(amountToMerge):
        mergedPileSize += heapq.heappop(heap)
    
    cost += mergedPileSize
    heapq.heappush(heap, mergedPileSize)

print(cost)