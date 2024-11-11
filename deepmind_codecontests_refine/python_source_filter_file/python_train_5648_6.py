# Couldn't solve. Made silly mistakes understanding the question. Tried wrong bases on paper

import heapq

t = int(input())
for _ in range(t):
    n = int(input())
    a = [0]*n

    # length, starting position
    zerosub = [(-n, 0)]
    heapq.heapify(zerosub)

    i = 1
    while zerosub:
        length, start = heapq.heappop(zerosub)
        print(length, start)
        length *= -1

        l = start
        r = length + l - 1

        if length%2==0:
            mid = (l+r-1)//2
            a[mid] = i
        else:
            mid = (l+r)//2
            a[mid] = i
        
        # print(l, r, mid)
        if mid - l:
            heapq.heappush(zerosub, (-(mid-l), l))
        if r - mid:
            heapq.heappush(zerosub, (-(r-mid), mid+1))
        
        i += 1
        
    print(a)

    
        

        
