import heapq
n = int(input())
a = list(map(int, input().split()))

a1 = a[:n]
ax = a[n:2*n]
a2 = list(map(lambda x: -x, a[2*n:]))
#print('a2', a2)

sum_a1 = sum(a1)
fdif1 = [sum_a1]
heapq.heapify(a1)
for i in range(n):
    p = heapq.heappushpop(a1,ax[i])
    fdif1.append(fdif1[-1]+ax[i]-p)
    
sum_a2 = sum(a2)
fdif2 = [sum_a2]
heapq.heapify(a2)
#print('a2', a2)
for i in range(n):
    p = heapq.heappushpop(a2,-ax[-1-i])
    fdif2.append(fdif2[-1]-ax[-1-i]-p)
fdif2.reverse()

fdif = [fdif1[i]+fdif2[i] for i in range(n)]
print(max(fdif))