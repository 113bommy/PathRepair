s = input()
ans=0
for i in range(len(s)//2):
    if s[i]!=s[~i]:
        ans+=1
print(ans)