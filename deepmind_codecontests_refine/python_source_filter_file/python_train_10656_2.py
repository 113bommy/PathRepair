n = int(input())
A = []
for i in range(n):
    A.append([])
    A[i] = list(map(int, input().split()))
li = -1
ri = -1
res = -1
for i in range(n):
    if A[i][0] < li:
        li = A[i][0]
    if A[i][1] > ri:
        ri = A[i][1]
for i in range(n):
    if A[i][0] == li and A[i][1] == ri:
        res = i
if res == -1:
    print(-1)
else:
    print(res + 1)
