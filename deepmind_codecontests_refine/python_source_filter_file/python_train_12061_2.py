N,W = map(int, input().split())
WV = [[int(i) for i in input().split()] for _ in range(N)]

MINW = WV[0][0]

W0,W1,W2,W3 = [],[],[],[]
for w,v in WV:
    if w == MINW: W0.append(v)
    elif w == MINW + 1: W1.append(v)
    elif w == MINW + 2: W2.append(v)
    elif w == MINW + 3: W3.append(v)

W0.sort(reverse=True)
W1.sort(reverse=True)
W2.sort(reverse=True)
W3.sort(reverse=True)

W0 = [0] + W0
W0 = [0] + W1
W0 = [0] + W2
W0 = [0] + W3

from itertools import accumulate

W0 = list(accumulate(W0))
W1 = list(accumulate(W1))
W2 = list(accumulate(W2))
W3 = list(accumulate(W3))

ans = 0
for cnt0 in range(len(W0)):
    for cnt1 in range(len(W1)):
        for cnt2 in range(len(W2)):
            for cnt3 in range(len(W3)):
                SUMW = cnt0 * MINW
                SUMW += cnt1 * (MINW + 1)
                SUMW += cnt2 * (MINW + 2)
                SUMW += cnt3 * (MINW + 3)

                if SUMW <= W:
                    SUMV = W0[cnt0]
                    SUMV += W1[cnt1]
                    SUMV += W2[cnt2]
                    SUMV += W3[cnt3]
                    ans = max(ans, SUMV)

print(ans)