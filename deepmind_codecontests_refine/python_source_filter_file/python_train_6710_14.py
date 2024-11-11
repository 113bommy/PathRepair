n=int(input())
s=list(input())

ans=0
for i in range(len(s)):
    #print(i,s[i])
    if s[i]=='1' :
        ans+=1
    else :
        break
print(ans+1)
