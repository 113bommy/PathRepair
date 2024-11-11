import math
t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    mid = math.ceil(n/2)
    if '0' not in s:
        if n%2==1:
            mid-=1
        print(1,mid,mid+1,2*mid)
        continue
    if '0' in s[0:mid]:
        ind=s.index('0')
        print(ind+1,n,ind+2,n)
    else:
        ind=s.index('0')
        print(1,ind+2,1,ind+1)

