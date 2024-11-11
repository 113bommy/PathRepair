import sys

input = sys.stdin.readline

s = input().strip()
n = len(s)
poss = [[False] * 2 for _ in range(n)]
poss[n - 2][0] = poss[n - 3][1] = True
for i in range(n - 4, -1, -1):
    poss[i][0] = s[i: i + 2] != s[i + 2: i + 4] and poss[i + 2][0] or poss[i + 2][1]
    poss[i][1] = s[i: i + 3] != s[i + 3: i + 6] and poss[i + 3][1] or poss[i + 3][0]

ans = set()
for i in range(5, n):
    if poss[i][0]:
        ans.add(s[i: i + 2])
    if poss[i][1]:
        ans.add(s[i:i + 3])

print(len(ans))
for x in ans:
    print(x)
