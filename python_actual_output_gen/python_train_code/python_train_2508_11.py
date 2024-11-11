s=input()
B=u=l=b=a=sa=r=0
for i in range(len(s)):
    if s[i]=='B':
        B+=1
    elif s[i]=='u':
        u+=1
    elif s[i]=='l':
        l+=1
    elif s[i]=='b':
        b+=1
    elif s[i]=='a':
        a+=1
    elif s[i]=='s':
        sa+=1
    elif s[i]=='r':
        r+=1
u//=2
a//=2
print(max([B,u,l,b,a,sa,r]))
