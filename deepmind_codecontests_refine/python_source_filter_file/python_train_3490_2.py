from heapq import * 

n, f, q = [int(s) for s in input().split()]
loves = [int(s) for s in input().split()]
k = []
onlines = set()
for i in range(q):
    ind, num = [int(s) for s in input().split()]
    if ind == 1:
        onlines.add(num - 1)
        if len(k)<f:
            heappush(k, loves[num - 1])
        else:
            heapreplace(k, loves[num-1])
    else:
        if num-1 in onlines and k[0] <= loves[num-1]:
            print("YES")
        else:
            print("NO")
