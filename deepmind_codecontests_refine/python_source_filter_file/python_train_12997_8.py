import heapq
N = int(input())
A = list(map(int, input().split()))

al = A[:N]
heapq.heapify(al)
sal = sum(al)
suml = [sal]
for i in range(N, 2*N):
    if al[0] < A[i]:
        tmp = heapq.heappop(al)
        heapq.heappush(al, A[i])
        sal += A[i]-tmp
    suml.append(sal)

ar = [-a for a in A[2*N:]]
heapq.heapify(ar)
sar = -sum(ar)
sumr = [sar]

ans = -10**15
for i in range(N, 2*N):
    if -ar[0] > A[3*N-1-i]:
        tmp = -heapq.heappop(ar)
        heapq.heappush(ar, -A[3*N-1-i])
        sar += A[3*N-1-i]-tmp
    sumr.append(sar)
for i in range(len(suml)):
    ans = max(ans, suml[i]-sumr[-i])
print(ans)
