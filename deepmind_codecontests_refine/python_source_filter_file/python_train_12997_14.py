import heapq
n = int(input())
A = list(map(int,input().split()))
L = A[:n]
R = A[2*n:]
R = list(map(lambda x:-x,R))
sum_l = [sum(L)]
sum_r = [sum(R)]
heapq.heapify(L)
heapq.heapify(R)
for i in range(n):
    elem = A[n+i]
    heapq.heappush(L,elem)
    sum_l.append(sum_l[-1] + elem -heapq.heappop(L))
for i in range(n):
    elem = -A[2*n-1-i]
    heapq.heappush(L,elem)
    sum_r.append(sum_r[-1] + elem -heapq.heappop(R))
ans = -float('inf')
sum_r = sum_r[::-1]
for i in range(len(sum_l)):
    ans = max(ans,sum_l[i] + sum_r[i])
print(ans)