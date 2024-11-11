from functools import *
from operator import *


def count_primitive(n):
    count = 0
    if n==2:
        return 0
    for i in range(2, n):
        flag, cur = 1, i

        for j in range(1, n - 2):
            cur = (cur * i) % n
            if cur == 1:
                flag = 0
                break

        if flag and (cur *i) % n == 1:
            count += 1
    return count


print(count_primitive(int(input())))
