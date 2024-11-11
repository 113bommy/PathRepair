# -*- coding: utf-8 -*-
"""
Created on Wed Jun 17 13:44:39 2020

@author: Mridul Garg
"""

o = int(input())
for _ in range(o):
    n = int(input())
    A = list(map(int, input().split(" ")))
    
    odd, even = [], []
    
    count = 0
    for u in range(len(A)):
        i = A[u]
        
        if i%2 == 1:
            odd.append(u)
            count += 1
        else:
            even.append(u)
    
    if count%2 == 1:
        odd.pop()
        even.pop()
    else:
        if len(even) >= 2:
            even.pop()
            even.pop()
        else:
            odd.pop()
            odd.pop()
    
    ans = []
    for i in range(0, len(even), 2):
        print(even[i], even[i+1])
        ans.append(even[i]+even[i+1])
    for i in range(0, len(odd), 2):
        ans.append(odd[i]+odd[i+1])
        print(odd[i],odd[i+1])
        
#    print(ans)
    