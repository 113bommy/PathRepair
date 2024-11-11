n=int(input())
ll=[]
for _ in range(n):
    x,l=map(int,input().split())
    ll.append((x+l,x-l))
ll=sorted(ll)
ans=0
c=-10**10
for t,s in ll:
    if c<=s:
        c=t
        ans+=1
print(ans)