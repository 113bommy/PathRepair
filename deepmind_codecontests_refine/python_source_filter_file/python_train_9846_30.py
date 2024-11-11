n=int(input())
a=list(map(int,input().split()))
ans,m=0,min(a)
for x in a:
    ans+=(x-m)
print(ans)
