l=lambda:map(int,input().split())
t=lambda:int(input())
ss=lambda:input()
#from math import log10 ,log2,ceil,factorial as f
#from itertools import combinations_with_replacement as c

n,m=l()
a=list(l())
d={}
for i in range(m):
    u,v=l()
    if u-1 not in d.keys():
        d[u-1]=[]
    if v-1 not in d.keys():
        d[v-1]=[]
    d[u-1].append(v-1)
    d[v-1].append(u-1)
#print(d)
s=0
v=[0]*(n)
for i in d.keys():
    if v[i]==0:
        q=[i]
        t=10000000
        while len(q):
            x=q.pop()
            t=min(a[x],t)
            for j in d[x]:
                if v[j]==0:
                    q.append(j)
                    v[j]=1
        s+=t        
for i in range(n):
    if not v[i]:
        s+=a[i]
print(s)


    
         

        
            
    



'''
5 2
2 5 3 4 8
1 4
4 5
outputCopy
10
inputCopy
10 0
1 2 3 4 5 6 7 8 9 10
outputCopy
55
inputCopy
10 5
1 6 2 7 3 8 4 9 5 10
1 2
3 4
5 6
7 8
9 10
outputCopy
15
'''