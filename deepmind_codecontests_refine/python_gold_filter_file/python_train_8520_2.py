# AOJ DSL_2_A "Range Minimum Query"
# SegmantTreeの実装

# 初期化最大値
INF = (1 << 31) - 1

class SegmentTree:
    def __init__(self, N):
        self.N = 2**(N-1).bit_length()
        self.data = [[INF, -1] for _ in range(2*self.N-1)]

    # k番目の値(0-indexed)をaに変更
    def update(self, k, a):
        self.data[k+self.N-1] = [a, k]
        k += self.N - 1
        while k > 0:
            k = (k-1)//2
            if self.data[2*k+1][0] < self.data[2*k+2][0]:
                self.data[k] = self.data[2*k+1][:]
            else:
                self.data[k] = self.data[2*k+2][:]

    # [l, r)の最小値取得
    # kがNodeの番号、対応する区間が[a, b)
    def query_min(self, l, r):
        L = l + self.N
        R = r + self.N
        s = [INF, -1]
        while L < R:
            if R & 1:
                R -= 1
                if s[0] > self.data[R-1][0]:
                    s = self.data[R-1]
            if L & 1:
                if s[0] > self.data[L-1][0]:
                    s = self.data[L-1]
                L += 1
            L >>= 1; R >>= 1
        return s


import sys
input = sys.stdin.readline
from bisect import bisect_left

N = int(input())
X = list(map(int, input().split()))
sortedX = sorted(X)

decided = [-1]*(N**2+1)
for i, x in enumerate(X):
    decided[x] = i+1

marge = SegmentTree(N+1)
remains = [0]*(N+1)
alreadyUsed = [None]*(N+1)
for i, x in enumerate(X):
    i += 1
    alreadyused = bisect_left(sortedX, x)
    if i != 1:
        marge.update(i, x-alreadyused-i)
    alreadyUsed[i] = alreadyused
    remains[i] = i-1

def solve():
    offset = 0
    for n in range(1,N**2+1):
        if decided[n] != -1:
            decided_num = decided[n]
            if remains[decided_num] > 0:
                return False, None
            remain = N-decided_num
            if remain < 0:
                return False, None
            if remain == 0:
                marge.update(decided_num, INF)
                remains[decided_num] = 0
            else:
                marge_now = (N**2-n)-(N-alreadyUsed[decided_num]-1)-remain+offset
                marge.update(decided_num, marge_now)
                remains[decided_num] = remain
        else:
            marge_now, num = marge.query_min(0, N+1)
            if marge_now-offset < 0 or marge_now == INF:
                return False, None
            remains[num] -= 1
            if remains[num] == 0:
                marge.update(num, INF)
            else:
                marge.update(num, marge_now+1)
            decided[n] = num
            offset += 1
    return True, decided[1:]

if __name__ == "__main__":
    ok, ans = solve()
    if ok:
        print("Yes")
        print(*ans)
    else:
        print("No")
