# -*- coding: utf-8 -*-

while True:
    try:
        A, B = input().split(), input().split()
        hit = sum([ 1 for i in range(len(A)) if A[i]==B[i] ])
        blow = sum([ 1 for i in range(len(A)) if B[i] in A ])
        print(str(hit) + ' ' +str(blow))
    except:
        break
