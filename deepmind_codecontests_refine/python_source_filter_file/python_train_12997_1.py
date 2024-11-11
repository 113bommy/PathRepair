N = int(input())

A = list(map(int,input().split()))
import heapq
L = A[:N]
heapq.heapify(L)
sum_L = sum(A[:N])
L_list = []
L_list.append(sum_L)
for i in range(N):
    sum_L += A[N+i]
    heapq.heappush(L,A[N+i])
    sum_L -= heapq.heappop(L)
    L_list.append(sum_L)

A = list(map(lambda x:-x, A[::-1]))
R = A[:N]
heapq.heapify(R)
sum_R = sum(A[:N])
R_list = []
R_list.append(sum_R)


for i in range(N):
    sum_R += A[N+i]
    heapq.heappush(R,A[N+i])
    sum_R -= heapq.heappop(R)
    R_list.append(sum_R)
maxi = -10000000000000000000000000000
R_list = R_list[::-1]
for i in range(N):
    maxi = max(maxi,L_list[i] + R_list[i])

print(maxi)
