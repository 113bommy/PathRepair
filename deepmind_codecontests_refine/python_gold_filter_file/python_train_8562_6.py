s=input()
i,ans,last=1,0,s[0]
while True:
    if i==len(s):
        if len(last)>0: ans+=1
        break
    if last[-1]!=s[i]:
        ans+=1
        last=s[i]
        i+=1
    else:
        if len(last)==4:
            ans+=1
            i+=1
            if i==len(s):break
            last=s[i]
            i+=1
        else:
            last+=s[i]
            i+=1
print(ans)
