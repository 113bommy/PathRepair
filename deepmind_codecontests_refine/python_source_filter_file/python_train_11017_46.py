N = int(input())
A = list(map(int, input().split()))
rec = 0
ind = 0
mi = False
for i in range(N):
    if A[i] < 0 and abs(A[i]) > rec:
        rec = abs(A[i])
        ind = i
        mi = True
    elif A[i] > 0 and A[i] > rec:
        rec = A[i]
        ind = i
        mi = False

ans = []
if mi:
    for i in range(N):
        ans.append((ind + 1, i + 1))
    for i in range(N - 1, 1, -1):
        ans.append((i + 1, i))
else:
    for i in range(N):
        ans.append((ind + 1, i + 1))
    for i in range(1, N):
        ans.append((i, i + 1))

print(len(ans))
for i in ans:
    print(i[0], i[1])