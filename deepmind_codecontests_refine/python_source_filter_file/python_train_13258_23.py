s,n=map(int,input().split())
a=[]
k=0
for i in range(n):
    x,y=map(int,input().split())
    a.append([])
    a[i].append(x)
    a[i].append(y)
b=sorted(a,key=(lambda x:x[0]))
for i in range(n):
    if s>=b[i][0]:
        s+=b[i][1]
    else:
        k=1
        break
print('YES' if k==0 else 'NO')