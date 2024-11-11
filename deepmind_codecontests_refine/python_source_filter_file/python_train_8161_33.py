import itertools
import math
import random

import time
def timer(f):
    def tmp(*args, **kwargs):
        t = time.time()
        res = f(*args, **kwargs)
        print("Время выполнения функции: %f" % (time.time()-t))
        return res

    return tmp

def genArray(length, lower, upper):
    return [random.randint(lower, upper) for i in range(length)]

#print(genArray(5, 4, 9))


n, k = map(int, input().split(' '))
s = ""
for i in range(n):
    for j in range(n):
        if i==j:
            s+=str(k)
        else:
            s+="0"
    s+="\n"
print(s)

