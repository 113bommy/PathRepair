n_arry = [int(i) for i in input().split()][:3]

n=n_arry[0]
p=n_arry[1]
k=n_arry[2]
if (p-k)>0:
    print('<<',end=' ')
if p-k>0:
    for i in range((k),0,-1):
        if p-i>0 and i >0:
            print(p-i,end=' ')
elif p-k-1<0:
    for a in range(1,p):
        print(a, end=' ')
print('(',p,')',sep='',end = ' ')
for i in range(1,k+1):
    if p+i<=n:
        print(p+i,end=' ')

if p+k<n:
    print('>>')