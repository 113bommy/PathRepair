import bisect
n=int(input())
m=[]
mm=[]
for i in range(n):
    x=list(map(int,input().split()))
    s=x[1:]
    if sorted(s)==s[::-1]:
        m.append(s[0])
        mm.append(s[-1])
m.sort()        
mm.sort()
ans=0
for i in range(len(m)):
    j=bisect.bisect_right(m,mm[i])
    ans=ans+len(m)-j
print(n*n-ans)