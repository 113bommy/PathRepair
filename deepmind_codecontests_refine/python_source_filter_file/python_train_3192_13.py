# -*- coding: utf-8 -*-
# @Time    : 2018/3/29 20:35
# @Author  : Yunjie Cao
# @FileName: A.py
# @Software: PyCharm
# @Email   ：Cyj19970823@gmail.com


import re

def solve():
    n = input()
    s = input()
    if ('??'in s or 'C?C' in s or 'Y?Y' in s or 'M?M' in s or s[0]=='?' or s[-1]=='?' and 'CC' not in s and 'YY' not in s and 'MM' not in s):
        print("YES")
    else:
        print("NO")

if __name__=="__main__":
    solve()