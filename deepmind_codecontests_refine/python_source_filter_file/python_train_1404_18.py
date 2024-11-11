n,k=map(int,input().split())
a=list(map(int,input().split()))
c=0
l=[]
li=[]
for z in range(n):
    li.append(z)
a, li = zip(*sorted(zip(a, li)))
for z in range(n):
    if(k>=a[z]):
        l.append(z)
        k-=a[z]
print(len(l))
for z in l:
    print(li[z],end=" ")