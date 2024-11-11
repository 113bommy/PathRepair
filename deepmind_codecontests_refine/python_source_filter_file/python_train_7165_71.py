N=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

adif,bdif=0,0
for i in range(N):
    if a[i]<b[i]:
        adif+=(b[i]-a[i])//2
    elif a[i]>b[i]:
        bdif+=a[i]-b[i]
if bdif*2<=adif:
    print('Yes')
else:
    print('No')