# -*- coding: utf - 8 -*-
"""""""""""""""""""""""""""""""""""""""""""""
|    author: mr.math - Hakimov Rahimjon     |
|    e-mail: mr.math0777@gmail.com          |
|    created: 04.05.2018 03:20              |
"""""""""""""""""""""""""""""""""""""""""""""
# inp = open("input.txt", "r"); input = inp.readline; out = open("output.txt", "w"); print = out.write
TN = 1


# ===========================================


def solution():
    n, k, m = map(int, input().split())
    sl = input().split()
    d_sl = {sl[i]: i+1 for i in range(n)}
    a = [-1]+list(map(int, input().split()))
    ans = 0
    m_x = max(a)
    min_s = [m_x]*(n+1)
    for i in range(k):
        s = list(map(int, input().split()))
        x = m_x
        sx = s[1:]
        for j in sx:
            if a[j] < x: x = a[j]
        for j in sx:
            min_s[j] = x
    st = input().split()
    for i in st:
        ans += min_s[d_sl[i]]
    print(ans)


# ===========================================
while TN != 0:
    solution()
    TN -= 1
# ===========================================
# inp.close()
# out.close()
