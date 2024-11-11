n=int(input())
a=[]
f=1
for i in range(n):
    a+=[input().strip()]
for i in range(n):
    for j in range(n):
        if a[i].find(a[j])==-1:
            a[i],a[j]=a[j],a[i]
            f=1
for i in range(n-1):
    if a[i+1].find(a[i])==-1:
        f=0
if f==0:
    print('NO')
else:
    print('YES')
    for i in range(n):
        print(a[i],end='\n')
        
