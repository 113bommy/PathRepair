x=int(input())
z=list(map(int,input().split()));ans=z[0]
for i in range(1,x):
    ans+=abs(z[i]-z[i-1])
print(ans)