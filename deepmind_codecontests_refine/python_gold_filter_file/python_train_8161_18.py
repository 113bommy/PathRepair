from itertools import permutations
n,k=map(int,input().split())
arr=[]
count=0
for m in range(n):
    lst=[0]*n
    lst[count]=k
    count+=1
    arr.append(lst)
for x in arr:
    print(*x)
