n = int(input())
s = input()
L = []
n_B = 0
n_W = 0
ans = []
for c in s:
    if c == 'W':
        n_W += 1
        x = 1
    else:
        n_B += 1
        x = 0
    L.append(x)
is_possible = True
if n_B % 2 and n_W % 2:
    is_possible = False

if n_W == 0 or n_B == 0:
    print(0)
elif is_possible:
    for i in range(n - 1):
        if L[i] == 1:
            L[i] = 0
            L[i + 1] = (L[i + 1] + 1) % 2
            ans.append(i + 1)
    if L[-1] == 1:
        for i in range(1, (n+1) // 2):
            ans.append(2 * i)
    print(len(ans))
    print(*ans)
else:
    print(-1)
