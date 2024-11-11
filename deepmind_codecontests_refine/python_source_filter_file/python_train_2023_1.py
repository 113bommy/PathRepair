Mod=1000000007
s=input()
n=len(s)
a,b,c,d=1,0,0,0
for i in range(0,n):
    if s[i]=='*':
        a,b,c,d=0,(a+b+d)%Mod,0,0
    elif s[i]=='?':
        a,b,c,d=(a+b+c)%Mod,(a+b+d)%Mod,0,0
    elif s[i]=='0':
        a,b,c,d=0,0,(a+c)%Mod,0
    elif s[i]=='1':
        a,b,c,d=0,0,b,(a+c)%Mod
    else:
        a,b,c,d=0,0,0,(b+d)%Mod
print(a+b+c)
