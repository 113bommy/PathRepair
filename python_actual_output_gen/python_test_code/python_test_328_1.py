n=int(input())
if n<3:
    print('NO')
else:
    a=[1]
    j=4
    while True:
        if j<=(2*n):
           a.append(j)
           j+=1
        else:
            break
        if j<=(2*n):
            a.append(j)
            j+=3
        else:
            break
    b=[]
    for i in range(len(a)):
        if i%2==0:
            b.append(a[i]+1)
        else:
            b.append(a[i]-1)
    a+=b
    print('YES')
    print(*a)