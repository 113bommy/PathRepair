from sys import stdin as si
from collections import Counter as C


class Solution:
    def bazinga(self, k,t):
        t2 = C([t[i] + t[i-1] for i in range(1, len(t))])
        return max(t2, key= lambda x: t2[x])

if __name__ == '__main__':
    #for i in range(int(si.readline().strip())):
    n = int(si.readline().strip())
    #m,n = map(int,si.readline().strip().split())
    t = list(si.readline().strip())
    S = Solution()
    print (S.bazinga(n,t))