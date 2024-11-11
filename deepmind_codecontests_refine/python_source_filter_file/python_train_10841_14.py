# -*- coding: utf-8 -*-
# @Time    : 2019/4/6 19:35
# @Author  : LunaFire
# @Email   : gilgemesh2012@gmail.com
# @File    : A. Ilya and a Colorful Walk.py


def main():
    n = int(input())
    c = list(map(int, input().split()))

    if c[0] != c[-1]:
        print(n - 1)
        return
    ret = 0
    for i in range(1, n - 1):
        if c[i] != c[0]:
            ret = max(ret, i - 1)
            ret = max(ret, n - 1 - i)
    print(ret)


if __name__ == '__main__':
    main()
