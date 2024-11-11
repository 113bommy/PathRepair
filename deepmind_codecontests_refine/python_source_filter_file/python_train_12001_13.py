# -*- coding: utf-8 -*-
"""
Created on Sat Sep 19 16:36:57 2020

@author: lakne
"""
t = int(input())
answers = []
for _ in range(t):
    x = 0
    nk = input().split()
    a = input().split()
    a_sorted = []
    for i in range(int(nk[0])):
        a_sorted.append(int(a[i]))
    a_sorted = sorted(a_sorted)
    for j in range(int(nk[0])-1):
        x += (int(nk[1])-a_sorted[-1-j])/a_sorted[0]
    answers.append(int(x))
for k in range(t):
    print(answers[k])