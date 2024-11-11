n=int(input())
a=list(input().split())
ans=len(set(a))
if ans%2==0:
    ans-1
print(ans)