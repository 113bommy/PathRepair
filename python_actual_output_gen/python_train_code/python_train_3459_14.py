s=input()
n=len(s)
if(n==1 or n==2):
    print(s)
else:
    ans=[s[0],s[1]]
    for i in range(2,n):
        k=len(ans)-1
        if(s[i]!=ans[k]):ans.append(s[i])
        else:
            if(ans[k]!=ans[k-1]):
                if(k>=2):
                    if(ans[k-1]!=ans[k-2]):ans.append(s[i])
                ans.append(s[i])
    print("".join(ans))
