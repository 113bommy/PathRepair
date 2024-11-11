t=int(input())
l=list(map(int,input().split()))

total=100/t
ans=0
for i in range(t):
    ans+=total*(l[i]/100)
print(ans)
