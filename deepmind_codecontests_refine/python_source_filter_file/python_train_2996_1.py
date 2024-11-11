import sys


input = sys.stdin.readline
N = int(input())
S = [input().replace('\n', '')[::-1] for _ in range(N)]
S1 = []
Slong = []
for s in S:
    if len(s) == 1:
        S1.append(s)
    else:
        Slong.append(s)

ans = 0
# 2文字以上同士のついを数える
Slong = sorted(Slong, key=lambda x: x[:-1])
for i in range(len(Slong)):
    s = Slong[i]
    j = i + 1
    n = len(s)-1
    while j<len(Slong) and Slong[j][:n] == s[:n]:
        ans += Slong[j][n:].find(s[-1]) != 0
        j += 1

# 1文字同士
S1 = sorted(S1)
for i in range(len(S1)):
    s = S1[i]
    j = i + 1
    while j<len(S1) and S1[j] == s:
        ans += 1
        j += 1


# 1->2以上
a2z = [chr(i) for i in range(97, 97+26)]
wcnt = {i: 0for i in a2z}
for s in Slong:
    for c in set(s):
        wcnt[c] += 1
for s in S1:
    ans += wcnt[s]

print(ans)
