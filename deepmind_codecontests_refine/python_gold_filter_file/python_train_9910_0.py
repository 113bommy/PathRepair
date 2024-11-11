#from bisect import bisect_left as bl                #c++ lowerbound bl(array,element)
#from bisect import bisect_right as br               #c++ upperbound br(array,element)
#from __future__ import print_function, division    #while using python2
from collections import defaultdict

def main():
    #sys.stdin = open('input.txt', 'r')
    #sys.stdout = open('output.txt', 'w')

    points = []
    n = int(input())
    z_to_xy = defaultdict(lambda : [])
    for i in range(n):
        x, y, z = [int(x) for x in input().split()]
        points.append([x, y, z, i])
        z_to_xy[z].append([x, y, i])
    
    # print(dict(z_to_xy))
    rem_global = []
    for z in z_to_xy:
        y_to_x = defaultdict(lambda : [])
        for p in z_to_xy[z]:
            y_to_x[p[1]].append([p[0], p[2]])
        rem = []
        # print(dict(y_to_x))
        for y in y_to_x:
            temp  = sorted(y_to_x[y])
            i = 0
            while i < len(temp)-1:
                print(temp[i][1]+1, temp[i+1][1]+1)
                i += 2
            if i == (len(temp) - 1):
                rem.append([y, temp[i][0], temp[i][1]])
        # print("rem: ", rem)
        temp2 = sorted(rem)
        i = 0
        while i < len(temp2)-1:
            print(temp2[i][-1]+1, temp2[i+1][-1]+1)
            i += 2
        if i == (len(temp2) - 1):
            rem_global.append([z, temp2[i][1], temp2[i][0], temp2[i][-1]]) #{z, x, y, i}

        # print("rem global: ", rem_global)    
    temp = sorted(rem_global)
    i = 0
    while i < len(temp)-1:
        print(temp[i][-1]+1, temp[i+1][-1]+1)
        i += 2

#------------------ Python 2 and 3 footer by Pajenegod and c1729-----------------------------------------
py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

import os, sys
from io import IOBase, BytesIO

BUFSIZE = 8192
class FastIO(BytesIO):
    newlines = 0
    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0,2), super(FastIO, self).write(s))[0])
        return s
    def read(self):
        while self._fill(): pass
        return super(FastIO,self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)

class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s:self.buffer.write(s.encode('ascii'))
            self.read = lambda:self.buffer.read().decode('ascii')
            self.readline = lambda:self.buffer.readline().decode('ascii')

sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')

if __name__ == '__main__':
   main()
