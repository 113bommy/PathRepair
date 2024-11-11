from sys import stdin as si
from collections import Counter as c


class Solution:

    def bazinga(self, n,m, k):
        mnp = sum(m[k[0]-1:k[1]-1])    # min number of participants
        diff = k[1]-k[0]
        mxp,ans = mnp, diff              # maximizing participants
        for i in range(1,n):
            # print (i,diff, mxp,mnp, sum(m[i: diff+i]))
            mxp +=  m[(k[0]-i-1 + n) % n]
            mxp -= m[(k[1]-i-1 + n) % n]
            if mxp > mnp:
                mnp,ans = mxp, i
        return ans +1


if __name__ == '__main__':
    #for i in range(int(si.readline().strip())):
    n = int(si.readline().strip())
    m = list(map(int, si.readline().strip().split()))
    k = tuple(map(int, si.readline().strip().split()))
    S = Solution()
    print(S.bazinga(n, m, k))



'''
http://codeforces.com/contest/939/problem/C
'''