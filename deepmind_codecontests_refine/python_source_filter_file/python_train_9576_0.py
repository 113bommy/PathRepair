# coding: utf-8

import sys

def coding(s):
    t = ''
    flag = True
    for i in s:
        if flag:
            t += i
            flag = False
        if i == 'a' or i == 'i' or i == 'u' or i == 'e' or i == 'o':
            flag = True;
    return t

def pre_possible(ls):
    flag = False
    for i in range(len(ls)):
        for j in range(i+1,len(ls)):
            if ls[i] == ls[j]:
                flag = True
    return flag

def possible(ls,k):
    flag = True
    for i in range(len(ls)):
        for j in range(i+1,len(ls)):
            if len(ls[i]) < k or len(ls[j]) < k:
                if ls[i] == ls[j]:
                    flag = False
                    break
                else:
                    continue

            if ls[i][0:k] == ls[j][0:k]:
                flag = False
                break
        if flag:
            break
    return flag

if __name__ == '__main__':
    while(1):
        n = int(input());
        if n == 0:
            break
        l = []
        for i in range(n):
            l.append(input())
        nl = []
        for i in l:
            nl.append(coding(i))
        sz = min([len(i) for i in l])
        ll = 0
        hh = 50
        if pre_possible(nl):
            print(-1)
            continue
        while True:
            mid = (ll + hh) // 2
            if ll == mid:
                print(hh)
                break
            if possible(nl,mid):
                hh = mid
            else:
                ll = mid