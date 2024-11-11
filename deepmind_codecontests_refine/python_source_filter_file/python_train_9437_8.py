# -*- coding: utf - 8 -*-
"""""""""""""""""""""""""""""""""""""""""""""
|    author: mr.math - Hakimov Rahimjon     |
|    e-mail: mr.math0777@gmail.com          |
|    created: 23.03.2018 21:09              |
"""""""""""""""""""""""""""""""""""""""""""""
# inp = open("input.txt", "r"); input = inp.readline; out = open("output.txt", "w"); print = out.write
TN = 1


# ===========================================


def solution():
    s = input()
    l = list(s)
    st = set(l)
    st = list(st)
    ans = "Yes"
    m_s = len(st)
    if m_s > 4 or m_s == 1: ans = "No"
    elif m_s == 2:
        if l.count(st[0]) == 1 or l.count(st[1]) == 1: ans = "No"
    elif m_s == 3:
        if (l.count(st[0]) == 1 or l.count(st[1]) == 1 or l.count(st[2]) == 1) and not (l.count(st[0]) == 1 > l.count(st[1]) > 1 or l.count(st[2]) > 1): ans = "No"
    print(ans)


# ===========================================
while TN != 0:
    solution()
    TN -= 1
# ===========================================
# inp.close()
# out.close()
