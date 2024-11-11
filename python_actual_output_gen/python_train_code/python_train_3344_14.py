n=int(input())
l=list(map(int,input().split()))
l.sort()
ans=0
for i in range(0,n,2):
    ans=abs(l[i]-l[i+1])
print(ans)
    