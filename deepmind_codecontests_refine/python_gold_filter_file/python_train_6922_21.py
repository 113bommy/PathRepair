a1,b1=list(map(int,input().split()))
k,m=list(map(int,input().split()))
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if a1<k or b1<m:
    print('No')
else:
    if a[k-1]<b[b1-m]:
        print('Yes')
    else:
        print('No')