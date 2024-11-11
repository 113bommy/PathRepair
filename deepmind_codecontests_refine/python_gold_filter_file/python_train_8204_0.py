n=int(input())
s=list(input())
ans=0
for i in range(n):
    ans=max(ans,len(set(s[:i])&set(s[i:])))
print(ans)