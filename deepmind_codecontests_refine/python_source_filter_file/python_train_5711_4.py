from itertools import accumulate

S = input()
T = input()
Q = int(input())
ABCD = [list(map(int, input().split())) for _ in range(Q)]

SL = [1 if s == "A" else 2 for s in S]
TL = [1 if t == "A" else 2 for t in T]

AcumS = [0] + list(accumulate(SL))
AcumT = [0] + list(accumulate(TL))

for a, b, c, d in ABCD:
    s = AcumS[b] - AcumS[a - 1]
    t = AcumT[d] - AcumT[c - 1]
    if (s - t) % 3 == 0:
        print("Yes")
    else:
        print("No")