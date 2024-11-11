import string
import math

def reversed_list(l, start, end):
    if start >= end:
        return l
    l[start], l[end] = l[end], l[start]
    return reversed_list(l, start + 1, end - 1)



def main_function():
    x, y, z, t_1, t_2, t_3 = [int(i) for i in input().split(" ")]
    if 2 * t_3 + abs(z - x) * t_2 + abs(x - y) * t_2 < abs(x - y) * t_1:
        return "YES"
    return "NO"


print(main_function())