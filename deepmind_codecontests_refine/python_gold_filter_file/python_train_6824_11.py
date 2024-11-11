n=int(input())
c=list(map(int,input().split()))
s=[]
s1=[]
for _ in range(n):
    s.append(input())
dp1=0
dp2=c[0]
s1.append(s[0][::-1])
for i in range(1,n):
    s1.append(s[i][::-1])
    l1=[]
    if dp1!=-1 and s[i]>=s[i-1]:
        l1.append(dp1)
    if dp2!=-1 and s[i]>=s1[i-1]:
        l1.append(dp2)
    l2=[]
    if dp1!=-1 and s1[i]>=s[i-1]:
        l2.append(dp1+c[i])
    if dp2!=-1 and s1[i]>=s1[i-1]:
        l2.append(dp2+c[i])
    if len(l1)!=0:
        dp1=min(l1)
    else:
        dp1=-1
    if len(l2)!=0:
        dp2=min(l2)
    else:
        dp2=-1
if dp1==-1 and dp2==-1:
    print(-1)
if dp1!=-1 and dp2!=-1:
    print(min(dp1,dp2))
if dp1!=-1 and dp2==-1:
    print(dp1)
if dp1==-1 and dp2!=-1:
    print(dp2)