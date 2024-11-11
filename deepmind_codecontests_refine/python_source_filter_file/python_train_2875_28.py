#!/usr/bin/env python3
# -*- coding: utf-8 -*-


n, k = map(int, input().split())
if n == k or k == 0:
    print(0, 0)
else:
    if n % 3 == 2:
        a = n // 3 + 1
        if k == a:
            print(1, (k - 1) * 2 + 1)
        elif k < a:
            print(1, k * 2)
        else:
            print(1, n - k)
    else:
        a = n // 3
        if k <= a:
            print(1, k * 3)
        else:
            print(1, n - k)
