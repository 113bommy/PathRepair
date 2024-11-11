#
# Created by Daniil Kozhanov. All rights reserved.
#               december 2016

n, m, k = list(map(int, input().split()))
dr = m * 2

if k <= dr:
    if k % 2 == 0:
        n1 = 1
        m1 = k // 2
        lr = "R"
    else:
        n1 = 1
        m1 = k // 2 + 1
        lr = "L"

elif k % dr == 0:
    n1 = k // dr
    m1 = m
    lr = "R"

else:
    n1 = k // dr + 1
    if k % 2 == 0:
        m1 = (k-(n-1)*dr) // 2
        lr = "R"
    else:
        m1 = (k-(n1-1)*dr) // 2 + 1
        lr = "L"
print(n1, m1, lr)