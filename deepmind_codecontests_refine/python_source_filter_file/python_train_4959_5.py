from math import gcd

m=int(input())
s=list(map(int,input().split()))
if m<=1:
    print('1')
    print(s[0])
    exit()
d=s[1]
for i in range(2,m):
    d=gcd(d,s[i])
if d!=s[0]:
    print(-1)
else:
    print(2*m)
    ans=[]
    for i in range(m):
        ans.append(s[i])
        ans.append(s[0])
    print(' '.join(map(str,ans)))