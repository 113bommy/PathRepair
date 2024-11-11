n=int(input())
n2=int(input())
lx=[]
q=0
while(q<2*n):
    lx.append(n2%10)
    n2=n2//10
    q+=1

l=lx[::-1]

l1=[]
l2=[]
for i in range(n):
    l1.append(l[i])
for i in range(n,2*n,1):
    l2.append(l[i])
l1.sort()
l2.sort()
i=0
j=0
c=0
d=0
while(i<n):
    if(l1[i]>l2[j]):
        c+=1
    elif(l[i]<l2[j]):
        d+=1
    i+=1
    j+=1
if(d==n or c==n):
    print("YES")
else:
    print("NO")
