t=int(input())
n=[]
for i in range(0,t):
    x=int(input())
    n.append(x)
arr=[]
for i in range(0,t):
    array=[]
    for j in range(0,n[i]):
        ele=j+1
        array.append(ele)
    arr.append(array)

from itertools import permutations
from itertools import combinations
for i in range(0,t):
    perm=permutations(arr[i])
    for p in perm:
        flag=0
        for k in range(0,len(p)):
            for l in range(k,len(p)):
                if l!=k:
                    ans=p[k]
                    for m in range(k,l):
                        ans=ans|p[m+1]
                    if ans<k-l+3:
                        flag=1
        if flag==0:
            print(p)
            break

                                    
                    
