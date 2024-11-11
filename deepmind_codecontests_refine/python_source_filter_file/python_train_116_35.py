import math
import os
import random
import re
import sys
from operator import itemgetter, attrgetter

if __name__ == '__main__':
    n, s = int(input()), input()
    res = ()
    for i in range(1, n):
        if ord(s[i]) < ord(s[i - 1]):
            res = (i - 1, i)
            break
    print("YES \n{0} {1}".format(res[0], res[1]) if len(res) > 0 else "NO")
    