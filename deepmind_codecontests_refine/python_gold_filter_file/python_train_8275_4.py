from math import sqrt
import sys
from typing import List, Union


def rl(int_: bool = True, is_split: bool = True) -> Union[List[str], List[int]]:
    if int_:
        return [int(w) for w in sys.stdin.readline().split()]
    if is_split:
        return [w for w in sys.stdin.readline().split()]
    return sys.stdin.readline().strip()


a, v = rl()
l, d, w = rl()


def time(u, s, a, v):
    vs = sqrt(u * u + 2 * a * s)
    # print("vs", vs)
    if vs <= v:
        return (vs - u) / a
    elif vs > v:
        dv = (v * v - u * u) / (2 * a)
        # print("dv", dv)
        if dv >= s:
            vd = sqrt(u * u + 2 * a * s)
            # print(vd)
            return (vd - u) / a
        else:
            return ((v - u) / a) + ((s - dv) / v)


if w >= v:
    print(time(0, l, a, v))
elif w < v:
    vd = sqrt(2 * a * d)
    # print("vd", vd)
    if vd <= w:
        print(time(0, l, a, v))
    elif vd > w:
        v_ = sqrt((w * w + 2 * a * d) / 2)
        # print(v_)
        if v_ <= v:
            td = (v_ / a) + ((v_ - w) / a)
        elif v_ > v:
            td = (v / a) + ((d - ((2 * v * v - w * w) / (2 * a))) / v) + ((v - w) / a)

        print(td + time(w, l - d, a, v))
