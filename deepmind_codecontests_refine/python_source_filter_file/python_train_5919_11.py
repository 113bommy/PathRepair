N = int(input())
A = list(map(int, input().split()))
if N == 1:
    print(0)
    quit()

A.append(A[N-1])
ans = 1
last = A[0]
s = 0
for i in range(N-1):
    if not(A[s] <= A[i] <= A[i+1]) and not(A[s] >= A[i] >= A[i+1]):
        s = i + 1
        ans += 1

print(ans)