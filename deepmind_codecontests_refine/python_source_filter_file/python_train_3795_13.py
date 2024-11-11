"""
instagram : essipoortahmasb2018
telegram channel : essi_python

"""
n=int(input())
a=[['*']*n for i in range(n)]
ind1=n//2
ind2=n//2+1
index=0
index2=n-1
for i in range(1,n+1,2):
    a[index][ind1:ind2]=i*'D'
    a[index2][ind1:ind2]=i*'D'
    ind1-=1
    ind2+=1
    index+=1
    index2-=1

for i in range(n):
    print(*a[i])
