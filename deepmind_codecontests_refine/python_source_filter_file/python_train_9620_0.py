s=input()
j=0
ans=0
f=1
for i in range(len(s)):
    if s[i]=='F':
        if f==1:
            j=i
            continue
        if ans==0:
            ans=i-j
        else:
            ans=max(ans+1,i-j)
        j+=1
    else:
        f=0
print(ans)