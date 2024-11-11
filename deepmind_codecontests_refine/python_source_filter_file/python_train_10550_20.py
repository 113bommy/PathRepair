import bisect
l=[0]*50001
for i in range(50001):
    if i==0 or i==1:
        l[i]=i
    else:
        l[i]=l[i-1]+i
n=int(input())
i=bisect.bisect_left(l,n)
j=2
f=0
while i>j:
    if l[i]+l[j]==n:
        f=1
        break
    elif l[i]+l[j]>n:
        i=i-1
    elif l[i]+l[j]<n:
        j=j+1
if f==1 or n==2:
    print('YES')
else:
    print('NO')