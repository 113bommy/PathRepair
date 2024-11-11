S=input()
ans=0
for i in range(len(S)//2):
    if S[i]!=S[-i]:
        ans+=1
print(ans)
