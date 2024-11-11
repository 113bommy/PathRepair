n=int(input())
a=list(map(int,input().split()))
ans=0
for i in a:
    if i > ans:
        ans += 1
print(ans)