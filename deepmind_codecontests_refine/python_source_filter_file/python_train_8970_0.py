n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = []
for i in range(n):
    b.append([a[i],0])
    a[i]//=2
    j=1
    while(a[i]>0):
        b.append([a[i],j])
        a[i]//=2
        j+=1
    b.append([a[i],j])
b = sorted(b, key = lambda x:x[0])
minop = 0
su = 0
for i in range(k):
    su += b[i][1]
minop = float('inf')
if(b[0][0]==b[k-1][0]):
    minop = su
for i in range(1,len(b)-k+1):
    if(b[i][0]!=b[i+k-1][0]):
        su += b[i+k-1][1]
        su -= b[i-1][1]
        continue
    su += b[i+k-1][1]
    su -= b[i-1][1]
    if(su<minop):
        minop = su
print(minop)