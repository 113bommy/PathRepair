import sys,os,io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
from math import gcd

class RangeQuery:
    def __init__(self, data, func=gcd):
        self.func = func
        self._data = _data = [list(data)]
        i, n = 1, len(_data[0])
        while 2 * i <= n:
            prev = _data[-1]
            _data.append([func(prev[j], prev[j + i]) for j in range(n - 2 * i + 1)])
            i <<= 1

    def query(self, start, stop):
        """func of data[start, stop)"""
        depth = (stop - start).bit_length() - 1
        return self.func(self._data[depth][start], self._data[depth][stop - (1 << depth)])

for _ in range (int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    d = [abs(a[i] - a[i-1]) for i in range (1,n)]
    rq = RangeQuery(d)
    ans = 0
    for i in range (n):
        l = i
        r = n-2
        while(l<=r):
            mid = (l+r)//2
            q = rq.query(i, mid+1)
            if q==1:
                r = mid-1
            else:
                ans = max(ans, mid-i+2)
                l = mid+1
    print(ans)