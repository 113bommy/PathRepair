import sys
import heapq
# from math import ceil,floor
# imx   port bisect

RI = lambda : [int(x) for x in sys.stdin.readline().split()]
rw = lambda : sys.stdin.readline().strip()


n,k = RI()
a = RI()

h = []
heapq.heapify(h)

for i in range(k):
    heapq.heappush(h,[a[i],i])
for i in range(k,n):
    temp = heapq.heappushpop(h,[a[i],i])
    # print(temp)
# print(h)
arr = []
summ = 0
# print(h)
for i in range(k):
    temp = h[i]
    summ+=(temp[0])
    arr.append(temp[1])
print(arr)
arr.sort()
ans = 1
for i in range(1,k):
    prev = arr[i-1]
    cur = arr[i]
    ans=  (ans*(cur-prev))%998244353
print(summ,ans)
