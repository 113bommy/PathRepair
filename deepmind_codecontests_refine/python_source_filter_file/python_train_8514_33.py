from bisect import bisect
S = input()
T = input()

cs = [[] for i in range(26)]
for i,s in enumerate(S):
    j = ord(s) - ord('a')
    cs[j].append(i)

for c in set(T):
    if not cs[ord(c) - ord('a')]:
        print(-1)
        exit()

rnd = k = 0
for t in T:
    ti = ord(t) - ord('a')
    i = bisect(cs[ti], k)
    if i == len(cs[ti]):
        k = cs[ti][0]
        rnd += 1
    else:
        k = cs[ti][i]

print(rnd*len(S) + k + 1)