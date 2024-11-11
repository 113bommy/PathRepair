s=input()
l=len(list(s))
ans=0
if int(s)<100:
    if int(s)>10:
        ans=(int(s)-9)*2+9
    else:
        ans=int(s)
else:
    s2="1"+("0"*(l-1))
    
    ans=(int(s)-int(s2)+1)*l
    # c=s2[0:l-1]
    c=str(int(s2)-int("1"+("0"*(l-2))))
    # print(c)
    i=l-1
    while(len(c)>=1):
        ans+=int(c)*len(c)
        i=i-1
        c=c[0:i]
print(ans)