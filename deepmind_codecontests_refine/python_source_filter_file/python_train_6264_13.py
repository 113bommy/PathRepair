n = int(input())
A = list(map(int, input().split()))
M = max(A)
cnt = 0
j = -1
for i, a in enumerate(A):
    if a == M:
        cnt += 1
        j = i
if cnt >= 2:
    print('NO')
    exit()

for i in range(min(0, j-1)):
    if A[i] >= A[i+1]:
        print('NO')
        exit()

for i in range(j, n-1):
    if A[i] <= A[i+1]:
        print('NO')
        exit()
print('YES')
