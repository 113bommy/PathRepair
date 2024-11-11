from collections import Counter
n=int(input())
x=list(map(int,input().split()))
x.sort()
cnt=Counter(x)
z=sorted(cnt,key=lambda k:cnt[k])
if len(z)==1:
    k=1
else:
    k=cnt[z[-2]]
for i in range(n):
    if cnt[x[i]]>k:

        cnt[x[i]]-=1
        x[i] = -1
z=[]
for i in x:
    if i!=-1:
        z.append(i)
i=0
p=z[0]
while i<len(z):
    if len(z)==1:
        break
    if z[i]==p:
        z[i]=-1
        z.append(p)
    else:
        p=z[i]
    i+=1
y=[]
for i in z:
    if i!=-1:
        y.append(i)
c=0
for i in range(1,len(y)):
    if y[i]>y[i-1]:
        c+=1
print(c)