n=int(input())
a=list(map(int,input().split()))
for i in range(n-1):
    if a[i+1]<a[i]:
        a[i]-=1
if sorted(a)==a:
    print('Yes')
else:
    print('No')