n=int(input())
ans=0
for i in range(n):
    ans+=(eval(input().replace(' ','-')[::-1]))+1
print(ans)