l=list(map(int,input().split()))
b=input()
ans=0
for i in range(4):
    ans+=l[0]*b.count(str(i+1))
print(ans)
