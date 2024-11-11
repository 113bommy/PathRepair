n=int(input())
s=input()
ans=0
for i in range(len(s)-1):
    if(s[i]==s[1+i]):
        ans+=1
print(ans)