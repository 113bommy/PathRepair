import math as ma
n=int(input())
arr=[int(i) for i in input().split()]
dic={}
if len(arr)==1:
    print('YES')
else:
    for i in range(n):
        if arr[i] not in dic:
            dic[arr[i]]=1
        else:
            dic[arr[i]]+=1

    m=0
    for i in dic:
        if dic[i]>m:
            m=dic[i]
    if n-m>=m-1:
        print("Yes")
    else:
        print("NO")
