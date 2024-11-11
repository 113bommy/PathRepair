from collections import *
import copy
N,K=map(int,input().split())
A=list(map(int,input().split()))

lst=[0]
for i in range(0,N):
    lst.append((A[i]%K+lst[i])%K)
for i in range(len(lst)):
    lst[i]-=i
    lst[i]%=K

dic={0:1}
count=0
for i in range(1,len(lst)):
    if lst[i] in dic:
        count+=dic[lst[i]]
        dic[lst[i]]+=1
    else:
        dic.update({lst[i]:1})
    a=i-K+1
    if a>=0:
        dic[lst[a]]-=1
print(count)
