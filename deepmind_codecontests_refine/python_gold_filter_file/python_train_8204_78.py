n=int(input())
s=input()
ans=0
for i in range(n):
    ans=max(ans,len(set(s[:i])&set(s[i:])))
print(ans)