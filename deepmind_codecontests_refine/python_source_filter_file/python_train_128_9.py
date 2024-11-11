# # -*- coding: utf-8 -*-
# """
# Created on Mon May 25 00:59:26 2020
#
# @author: Lakshya
# """
#
# n = int(input())
# k = 0
# while k < n:
#     num = int(input())
#     l = int(input())
#     a = []
#     i = 0
#     while i < num:
#         a.append(input())
#         i+=1
#     t = 0
#     test = [0 for i in range(l)]
#     i = 0
#     t = 0
#     while i<l:
#         ch = a[0][i]
#         j = 1
#         d = {}
#         d[ch] = 1
#         f = 0
#         m = 0
#         m2 = ''
#         while j<num:
#             if a[j][i]!=ch and f == 0:
#                 f = 1
#                 t+=1
#             if a[j][i] not in d:
#                 d[a[j][i]] = 1
#                 if d[a[j][i]]>m:
#                     m = d[a[j][i]]
#                     m2 = a[j][i]
#             else:
#                 d[a[j][i]]+=1
#                 if d[a[j][i]]>m:
#                     m = d[a[j][i]]
#                     m2 = a[j][i]
#             j+=1
#         test[i] = m2
#         i+=1
#     if t>2:
#         print("-1")
#     else:
#         f = 0
#         ans = ""
#         i = 0
#         while i<l:
#             ans+=test[i]
#             i+=1
#         print(ans)
#     k+=1
n = int(input())
while n>0:
    n-=1
    l,m = map(int,input().split())
    arr1 = [int(x) for x in input().split()]
    arr2 = [int(x) for x in input().split()]
    ans = []
    i = 0
    k = 0
    while i < (l):
        j = k
        while j < (m):
            if arr1[i] == arr2[j]:
                ans.append(arr1[i])
                k = j+1
                break
            j+=1
        i+=1
    if len(ans) > 0:
        print("YES")
        print(len(ans)," ",ans[-1])
    else:
        print("NO")
