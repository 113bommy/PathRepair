import sys
from itertools import accumulate
from bisect import bisect
def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    ac = [0] + list(accumulate(A))

    def calc(lst): return abs(max(lst) - min(lst))
    def sm(l,r): return ac[r+1] - ac[l]
    def get_min_max(l,r):
        if r-l <= 1: return [A[l], A[r]]
        med = ac[l] + sm(l,r) / 2
        i = bisect(ac, med, l+1, r+1)
        r1 = [sm(l,i-1), sm(i,r)]
        if i-1 == l: return r1
        r2 = [sm(l,i-2), sm(i-1,r)]
        return r1 if calc(r1) < calc(r2) else r2

    ans = 10**18
    for R_left in range(2,N-2):
        PQ_mm = get_min_max(0, R_left-1)
        RS_mm = get_min_max(R_left, N-1)
        ans = min(ans, calc(PQ_mm + RS_mm))
    print(ans)

if __name__ == '__main__':
    main()