import heapq

"""input"""
n, k, q = [int(i) for i in input().split()]
t=[[]]*n
a = [int(i) for i in input().split()]
for i in range(n):
    t[i]=[i,a[i]]
    
"""start"""
heap = []

for i in range(q):
    
    type, id = [int(i) for i in input().split()]
    
    if type == 1:
        
        if len(heap) >= k:
            
            heapq.heappushpop(heap,t[id-1])
            
        else:
            
            heapq.heappush(heap,t[id-1])

    if type == 2:

        if t[id-1] in heap:
            print("YES")
        else:
            print("NO") 
    
