import math
n=int(input())
a=list(map(int,input().split()))
j=1
p=a[j]
q=max(a)
while j<n:
    p=math.gcd(p,a[j])
    if p==1:
        break
    else:
        j=j+1
res=(q//p )-n
if res%2==0:
    print('Bob')
else:
    print('Alice')
