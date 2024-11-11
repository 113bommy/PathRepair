s=input()
i,j=0,len(s)-1
ans=[]
while i<j:
    while i<j and s[i]!='(':
        i+=1
    while i<j and s[j]!=')':
        j-=1
    if i<j:
        ans.append(i+1)
        ans.append(j+1)
        i+=1
        j-=1
ans.sort()
if ans:
    print(1)
    print(len(ans))
    print(*ans)
else:
    print(0)