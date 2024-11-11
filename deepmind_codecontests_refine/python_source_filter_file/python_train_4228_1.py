n=int(input())
a = list(map(int, input().strip().split(' ')))
b = list(map(int, input().strip().split(' ')))
l=[0]*n
k=[0]*n
for j in range(n):
    if a[j]==b[j] and l[a[j]-1]==0:
        l[a[j]-1]=1
        k[j]=a[j]
if l.count(0)==1:
    l1=l.index(0)
    l2=k.index(0)
    k[l2]=l1+1
else:
    l1=l.index(0)
    l2=l[l1+1:].index(0)
    l2+=(l1+1)
    l3=k.index(0)
    l4=k[l3+1:].index(0)
    l4+=(l3+1)
    
    if (a[l3]==b[l4] and a[l4]==b[l3]) or (a[l3]==a[l4] and b[l3]==b[l4]):
        k[l3]=l1+1
        k[l4]=l2+1
    elif l[a[l3]-1]==1:
        k[l3]=b[l3]
        k[l4]=a[l4]
    elif l[a[l4]-1]==1:
        k[l4]=b[l4]
        k[l3]=a[l3]
    elif l[b[l3]-1]==1:
        k[l3]=a[l3]
        k[l4]=b[l4]
    elif l[b[l3]-1]==1:
        k[l4]=a[l4]
        k[l3]=b[l3]
    
for j in range(n):
    print(k[j],end=" ")