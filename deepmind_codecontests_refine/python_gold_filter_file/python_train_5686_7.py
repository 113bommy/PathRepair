n=int(input())
a=[]
for i in range(n):
    a.append(list(map(int,input().split())))
a.sort()
b=a[0][1]
c=-1
e=0
for i in range(1,n):
    if a[i][0]>b:
        b=a[i][1]
    elif a[i][0]>c:
        c=a[i][1]
    else:
        e=1
        break
if e==1:
    print("NO")
else:
    print("YES")