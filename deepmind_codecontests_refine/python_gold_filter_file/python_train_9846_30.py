n=int(input())
a=list(map(int,input().split()))
ans,m=0,max(a)
for x in a:
    ans+=(m-x)
print(ans)
