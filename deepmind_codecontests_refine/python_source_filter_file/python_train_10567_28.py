from sys import stdin, stdout

def trace(f):
    def traced(*args, **kw):
        print("calling {} with args {}, {}".format(f.__name__, args, kw))
        return f(*args, **kw)
    return traced

#@trace
def f(x):
    print(x)

def read():
    return stdin.readline()[:-1]

def readarr(sep=None, maxsplit=-1):
    return read().split(sep, maxsplit)

def readint():
    return int(read())

def readintarr(sep=None, maxsplit=-1):
    return [int(a) for a in readarr(sep, maxsplit)]

def write(*args, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    stdout.write(sep.join(str(a) for a in args) + end)

def writearr(arr, sep=' ', end='\n'):
    stdout.write(sep.join(str(a) for a in arr) + end)

from collections import deque
from itertools import islice
s = read()
m = readint()
d = deque(s)
for t in range(m):
    L, R, k = readintarr()
    k = k % 10000
    L, R = L-1, R
    mid = deque(islice(d, L, R))
    mid.rotate(k)
    d = deque(islice(d, 0, L)) + mid + deque(islice(d, R, len(d)))
write("".join(d))

