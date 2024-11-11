def f(a):
    b=len(a)
    if b>=4 and a[-4:]=='lios':
        return [1,1]
    if b>=5 and a[-5:]=='liala':
        return [1,2]
    if b>=3 and a[-3:]=='etr':
        return [2,1]
    if b>=4 and a[-4:]=='etra':
        return [2,2]
    if b>=6 and a[-6:]=='initis':
        return [3,1]
    if b>=6 and a[-6:]=='inites':
        return [3,2]
    return -1
a=[f(i) for i in input().split()]
n=len(a)
if -1 in a or [i[1] for i in a]!=[a[0][1]]*n:
    print('NO')
else:
    i,j=0,n-1
    while i<n and a[i][0]==1:
        i+=1
    while j>=0 and a[j][0]==3:
        j-=1
    print('YES' if i==j or n==1 else 'NO')