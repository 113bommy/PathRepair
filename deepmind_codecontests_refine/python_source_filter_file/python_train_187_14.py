N=int(input())
ans=-10*9
s=["".join(list(input().split())) for i in range(N)]
t=[list(map(int,input().split())) for i in range(N)]
for j in range(1,1024):
    q=0
    for i in range(len(s)):
        q+=t[i][(bin(int(s[i],2)&j)).count("1")]
    ans=max(ans,q)
print(ans)
