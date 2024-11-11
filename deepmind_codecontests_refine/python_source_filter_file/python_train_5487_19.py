# -*- coding: utf - 8 -*-
"""""""""""""""""""""""""""""""""""""""""""""
|    author: mr.math - Hakimov Rahimjon     |
|    e-mail: mr.math0777@gmail.com          |
|    created: 01.06.2018 19:58              |
"""""""""""""""""""""""""""""""""""""""""""""
# inp = open("input.txt", "r"); input = inp.readline; out = open("output.txt", "w"); print = out.write
TN = 1


# ===========================================


def solution():
    n = int(input())
    l = []
    a = []
    d = {}
    ans = 1
    for i in range(n):
        l.append(input())
        a.append(len(l[i]))
        try:
            x = d[a[i]]
        except:
            d[a[i]] = l[i]
        else:
            if d[a[i]] != l[i]:
                ans = 0
    a = list(sorted(a))
    for i in range(1,n):
        for j in range(i):
            if d[a[j]] != d[a[i]]:
                ans = 0
    if ans:
        print("YES")
        for i in a:
            print(d[i])
    else:
        print("NO")


# ===========================================
while TN != 0:
    solution()
    TN -= 1
# ===========================================
# inp.close()
# out.close()
