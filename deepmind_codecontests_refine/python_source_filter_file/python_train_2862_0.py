#!/usr/bin/env python
# -*- coding: utf-8 -*-

n,k = map(int,input().split())
M = [list( map(int,input().split()))[1:] for i in range(k)]
matryoshkas = 0

for i in range(k):
    if M[i][0] == 1:
        for j in range(len(M[i])-1):
            if M[i][j] + 1 != M[i][j+1]:
                matryoshkas += len(M[i]) - 1
                break
    else:
        matryoshkas += len(M[i]) - 1
print(2 * matryoshkas + k - 1)
