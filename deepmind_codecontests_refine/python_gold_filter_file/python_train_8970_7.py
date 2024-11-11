n, k = map(int, input().split())
A = list(map(int, input().split()))
A.sort()

B = [0]*(2*10**5+1)
C = [0]*(2*10**5+1)
for i in range(n):
    a = A[i]
    cnt = 0
    while a:
        if C[a] < k:
            B[a] += cnt
            C[a] += 1
        a = a//2
        cnt += 1
    if C[a] < k:
        B[a] += cnt
        C[a] += 1

#print(B[0:10])
#print(C[0:10])
ans = 10**18
for i in range(len(C)):
    if C[i] >= k:
        ans = min(B[i], ans)
print(ans)
