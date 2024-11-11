n=int(input())
a=list(map(int,input().split()))
p=a.count(1)
m=a.count(2)
s=a.count(3)
print(min(p,m,s))
if min(p,m,s)==0:
    exit()
i1=[]
i2=[]
i3=[]
for i in range(n):
    if a[i]==1:
        i1.append(i)
    if a[i]==2:
        i2.append(i)
    if a[i]==3:
        i3.append(i)
for i in range(min(p,m,s)):
    x=" "
    print(str(i1[i])+x+str(i2[i])+x+str(i3[i]))