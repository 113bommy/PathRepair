s=[None,None]
s1=input()
s2=input()
s[0]=s1
s[1]=s2
ans=0
for i in range(len(s1)):
    if s[0][i]=='0' and s[0][i]=='0':
        if i+1!=len(s1):
            if s[0][i+1]=='0':
                s[0]=s[0][0:i]+"//"+s[0][i+2::]
                s[1]=s[1][0:i]+"/"+s[1][i+1::]
                ans+=1
            elif s[1][i+1]=='0':
                s[1]=s[1][0:i]+"//"+s[1][i+2::]
                s[0]=s[0][0:i]+"/"+s[0][i+1::]
                ans+=1
    elif s[0][i]=='0':
        if i+1!=len(s1):
            if s[0][i+1]=='0' and s[1][i+1]=='0':
                s[0]=s[0][0:i]+"//"+s[0][i+2::]
                s[1]=s[1][0:i+1]+"/"+s[1][i+2::]
                ans+=1
    elif s[1][i]=='0':
        if i+1!=len(s1):
            if s[0][i+1]=='0' and s[1][i+1]=='0':
                s[1]=s[1][0:i]+"//"+s[1][i+2::]
                s[0]=s[0][0:i+1]+"/"+s[0][i+2::]
                ans+=1

print(ans)
