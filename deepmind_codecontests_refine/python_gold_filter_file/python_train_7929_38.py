from collections import defaultdict
d={}
d=defaultdict(int)
d1={}
d1=defaultdict(int)
n=int(input())
l=list(map(int,input().split()))
n1=int(input())
l1=list(map(int,input().split()))
for i in l:
    d[i]+=1
for i in l1:
    d1[i]+=1
c=0
for i in d:
    for j in d1:
        k=i+j
        if(d[k]==0 and d1[k]==0):
            print(i,j)
            c=1
        if(c):
            break
    if(c):
        break