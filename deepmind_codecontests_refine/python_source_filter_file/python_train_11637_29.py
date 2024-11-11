from collections import Counter, deque

N = int(input())
A = list(map(int, input().split())) + [N+1]
B = list(map(int, input().split())) + [N+1]
C = [0]
D = [0]

AB_cn = Counter(A+B)
if AB_cn.most_common()[0][1] > N:
    print("No")
else:
    print("Yes")
    for i in range(N+1):
        if len(C) != A[i]:
            C.extend([i]*(A[i]-len(C)))
        if len(D) != B[i]:
            D.extend([i]*(B[i]-len(D)))
    ans = 0
    for i in range(N):
        curr = C[i+1] - D[i]
        ans= max(curr, ans)
    B = B[:-1]
    ans = [B[(i-x)%N] for i in range(N)]
 
    print(*ans)
