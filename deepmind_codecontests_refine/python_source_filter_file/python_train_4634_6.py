a=str(input())
n=len(a)
j=1
c=0
for i in 'hello':
    for k in range(j,n):
        j=j+1
        if a[k]==i:
            c=c+1
            break;
    if c==i:
        break
if c!=5:
    print('NO')
else:
    print('YES')