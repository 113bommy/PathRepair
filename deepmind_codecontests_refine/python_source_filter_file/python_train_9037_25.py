n = int(input())
A = [int(input()) for i in range(n)]

if A[0] != 0:
    print(-1)
    exit()

for i in range(1, n):
    if A[i] > A[i-1]+1:
        print(-1)
        exit()

ans = 0
for i in reversed(range(1, n)):
    if A[i-1] >= A[i]-1:
        ans += 1
    else:
        ans += A[i]

print(ans)
