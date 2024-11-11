n=int(input())
l=[]
for z in range(n):
    s=input()
    l.append(s)
a=['NO']
c=0
for i in range(1,n):
    c=0
    for j in range(i):
        if l[j]==l[i]:
            c=1
            break;
    if c==1:a.append('YES')
    else:a.append('NO')
for i in range(n):
    print(a[i])