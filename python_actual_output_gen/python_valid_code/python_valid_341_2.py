N = int(input())
A = list(map(int,input().split()))

A.sort(reverse=True)

ans = []
i = 0
while i < N-2:
    if A[i] == A[i+1]:
        ans.append(A[i])
        i += 1
    if len(ans) == 2: break
    i += 1

if len(ans) in (0,1): print(0)
else: print(ans[0]*ans[1])