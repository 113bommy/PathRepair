S=input()
n=len(S)
l=0
r=n-1
ans=0
while l+1<=r:
    if S[l]=='x' and S[l]!=S[r]:
        ans+=1
        l+=1
    elif S[r]=='x' and S[l]!=S[r]:
        ans+=1
        r-=1
    elif S[l]==S[r]:
        r-=1
        l+=1
    else:
        ans-=1
        break
print(ans)



