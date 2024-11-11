# -*- coding: utf - 8 -*-
"""""""""""""""""""""""""""""""""""""""""""""
|    author: mr.math - Hakimov Rahimjon     |
|    e-mail: mr.math0777@gmail.com          |
|    created: 24.03.2018 20:04              |
"""""""""""""""""""""""""""""""""""""""""""""
# inp = open("input.txt", "r"); input = inp.readline; out = open("output.txt", "w"); print = out.write
TN = 1


# ===========================================


def solution():
    n, m = map(int, input().split())
    lst = []
    ans = "Yes"
    for i in range(n):
        lst.append(list(input()))
    l = []
    for i in range(n):
        k = []
        for j in range(m):
            if lst[i][j] == "#":
                k.append(j)
        l.append(k)
    R = []
    r = []
    C = []
    for i in range(n):
        if i not in r:
            k = [i]
            for j in range(i+1, n):
                if l[i] == l[j]: k.append(j)
                else:
                    for x in l[i]:
                        if x in l[j]:
                            ans = "No"
                            break
            R.append(k)
            r += k
            C.append(l[i])
    if len(R) != len(C):
        ans = "No"
    print(ans,R,C,r)


# ===========================================
while TN != 0:
    solution()
    TN -= 1
# ===========================================
# inp.close()
# out.close()
