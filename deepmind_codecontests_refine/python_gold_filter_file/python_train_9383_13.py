from sys import stdin
n,m,k=map(int,stdin.readline().strip().split())
s=list(map(int,stdin.readline().strip().split()))
s.sort()
acum=[0]
for i in range(n-1,-1,-1):
    acum.append(acum[-1]+s[i])
acum.reverse()
acum.pop()
y=min(n*m,k)
ans=(sum(s)+y)/n
for i in range(min(n-1,k)):
    k-=1
    y=min((n-i-1)*m,k)
    ans=max(ans,(acum[i+1]+y)/(n-i-1))
print(ans)
    
