q=int(input())
a=[]*q
for i in range(2*q):
    a.append(input())
for i in range(0,q*2-1,2):
    if set(a[i])==set(a[i+1]):
        print('YES')
    else:
        print('NO')