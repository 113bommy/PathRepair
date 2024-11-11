N = int(input())
A = list(map(int, input().split()))

MAX, MAX_index = 0, -1
positive_flg = True
for i, a in enumerate(A):
    if abs(a) > MAX:
        if a > 0:
            positive_flg = True
        else:
            positive_flg = False
        MAX = abs(a)
        MAX_index = i

ans = []
for i in range(N):
    ans.append((MAX_index, i))
if positive_flg:
    for i in range(N - 1):
        ans.append((i, i + 1))
else:
    for i in reversed(range(N - 1)):
        ans.append((i + 1, i))


print(len(ans))
for x, y in ans:
    print(x + 1, y + 1)
