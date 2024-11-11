__author__ = 'Utena'
import operator
n,s=map(int,input().split())
p=[list(map(int,input().split()))for i in range(n)]
p=sorted(p,key=operator.itemgetter(0,1),reverse=0)
t=[]
for j in range(n):
    t.append(p[j][0]+p[j][1])
print(max(t))