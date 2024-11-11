x=int(input())
left=dict()
lset=set()
rset=set()
q=[0]*x
i=0
while i<x:
    l=[int(j) for j in input().split()]
    left[l[0]]=l[1]
    lset.add(l[0])
    rset.add(l[1])
    i+=1
i=lset.difference(rset).pop()
j=0
print(i)
q[0]=i
k=1
while k<x:
    q[k]=left[j]
    k+=1
    if k<x:
        q[k]=left[i]
    k+=1
    i=left[i]
    j=left[j]
print(" ".join([str(k) for k in q]))
