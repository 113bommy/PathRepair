from sys import stdin as si
from collections import Counter as c


class Solution:

    def largest_one(self, a):
        return (1 << len(bin(a)) - 3) - 1

    def largest_pow_2(self,a):
        return 1 << (len(bin(a)) - 3)

    def bazinga(self,n,m):
        if n==m:    return n
        elif m & (m+1) == 0: return m

        if len(bin(n)) < len(bin(m)):
            return self.largest_one(m)   #-3 coz of 0b
        else:
            np2 = self.largest_pow_2(m)
            if n<=np2<=m:   return np2-1
            return self.bazinga(n-np2,m-np2) + np2




if __name__ == '__main__':
    for i in range(int(si.readline().strip())):
        n,m = map(int, si.readline().strip().split())
        #m = list(map(int, si.readline().strip().split()))
        S = Solution()
        print(S.bazinga(n,m))


'''
http://codeforces.com/contest/484/problem/A
'''