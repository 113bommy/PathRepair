# p = print
# def print(x):    
#     p(x, end='')

import functools

def readint():
    return list(map(int, input().split()))

class _dict():
    def __init__(self):
        self.dict = dict()
    
    def __getitem__(self, key):
        if key in self.dict:
            return self.dict[key]
        else:
            return 0
    
    def __setitem__(self, key, value):
        self.dict[key] = value

def comparator(x, y):
    return x < y
    
comparator = functools.cmp_to_key(comparator)

yes = "YES\n"
no = "NO\n"

######################################################

tc, = readint()

while tc > 0:
    tc-=1

    l1 = readint()
    l1.sort()
    print(l1[0] * l1[3])