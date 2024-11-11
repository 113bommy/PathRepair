n = int(input())
D = []
U = []
for i in range(n):
    a, b = map(int, input().split())
    if a < b:
        U.append((a, b, i + 1))
    else:
        D.append((a, b, i + 1))

if len(U) <= len(D):
    D = sorted(D, key=lambda x: x[0])
    ans = []
    for i in range(len(D)):
        ans.append(D[i][2])
else:
    U = sorted(U, key=lambda x: -x[0])
    ans = []
    for i in range(len(U)):
        ans.append(U[i][2])

print(len(ans))
print(*ans)
