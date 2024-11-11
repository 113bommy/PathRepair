import bisect
N = int(input())
S = [input() for _ in range(N)]
T = input()

S1 = []
S2 = []
for s in S:
    S1.append(s.replace('?', 'A'))
    S2.append(s.replace('?', 'Z'))
S1 = sorted(S1)
S2 = sorted(S2)
ans1 = bisect.bisect_left(S1, T)+1
ans2 = bisect.bisect_left(S2, T)+1

print(*range(ans1, ans2+1))
