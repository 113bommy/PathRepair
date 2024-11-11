n=int(input())
a=list(map(int,input().split()))
if len(a)%2==0 or a[0]%2==0 or a[-1]%2==0:
    print('Yes')
else:
    print('No')
