import sys
from collections import Counter
n,k=map(int,input().split())
l=[]
for i in range(n) :
    p,q,t=map(str,sys.stdin.readline().split())
    t=int(t)
    l.append([[p,q],t])
#print(l)
p=[]
for i in range(n) :
    for j in range(i+1,n) :
        if l[j][1]-l[i][1] >k :
            break
        if Counter(l[i][0]) == Counter(l[j][0]) and l[j][1]-l[i][1]<=k and l[j][1]-l[i][1] >0 and l[j]!=l[i]:
            #print(l[i][0])
            if l[i][0] not in p and l[i][0][::-1] not in p :
                 p.append(l[i][0])
print(len(p))
if len(p)==0 :
    exit(0)
for i in p:
    print(i[0],i[1])