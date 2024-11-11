t=list(map(int,input().strip().split(' ')))
w=list(map(int,input().strip().split(' ')))
h=list(map(int,input().strip().split(' ')))
ans=0
for i in range(5):
    x=500*(i+1)
    ans+=max(0.3*x,(x-((x*t[i])//250)-50*w[i]))
ans+=100*h[0]
ans-=50*h[1]
print(ans)
