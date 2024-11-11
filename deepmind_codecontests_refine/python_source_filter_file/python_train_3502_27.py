# -*- coding: utf - 8 -*-
"""""""""""""""""""""""""""""""""""""""""""""
|    author: mr.math - Hakimov Rahimjon     |
|    e-mail: mr.math0777@gmail.com          |
|    created: 29.01.2018 19:46              |
"""""""""""""""""""""""""""""""""""""""""""""
# inp = open("input.txt", "r"); input = inp.readline; out = open("output.txt", "w"); print = out.write
TN = 1


# ===========================================


def solution():
    n, m = map(int, input().split())
    names = []
    ips = []
    for i in range(n):
        n, ip = input().split()
        names.append(n)
        ips.append(ip)
    opers = []
    ip_s = []
    for i in range(m):
        o, ip = input().split()
        opers.append(o)
        ip_s.append(ip)
    for i in range(m):
        ind = ips.index(ip_s[i][:-1])
        print(str(opers[i])+" "+str(ip_s[i])+"; #"+str(names[ind]))


# ===========================================
while TN != 0:
    solution()
    TN -= 1
# ===========================================
# inp.close()
# out.close()
