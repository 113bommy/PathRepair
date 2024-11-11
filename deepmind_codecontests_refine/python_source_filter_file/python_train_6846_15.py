# cf 988 A 800
n, k = map(int, input().split())
A = [*zip(map(int, input().split()), range(1, n + 1))]
A.sort(key=lambda x:x[0])
team = []
for i in range(len(A)):
    if not team or team[-1] != A[i][0]:
        team.append(A[i][1])
    if len(team) == k:
        break
if len(team) < k:
    print("NO")
else:
    print("YES")
    print(" ".join([str(x) for x in team]))
