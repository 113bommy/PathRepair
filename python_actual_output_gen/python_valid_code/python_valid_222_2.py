n=int(input())
x=[]
for _ in range(n):
    a,b=map(int,input().split())
    x.append([abs(a-b),a,b])
x.sort(reverse=True)
ans=0
for i in range(n):
    if i%2==0: ans+=x[i][1]
    else: ans-=x[i][2]
print(ans)