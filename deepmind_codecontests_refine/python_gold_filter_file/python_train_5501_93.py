n,m,k = map(int,input().split())
li = []
for i in range(n+1):
    for j in range(m+1):
        li.append(i*m + j*n - 2*i*j)
if k in li:
    print('Yes')
else:
    print('No')