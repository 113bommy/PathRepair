s=input()
#find first 4 letters
def check(a1,a2,ans):
    s=''
    c1=c2=c3=None
    c1=ans[-1]
    c2=ans[-2]
    if len(ans)>=3:
        c3=ans[-3]
    else:
        c3=None
    if c1==c2:
        if c1==a1 and c1==a2:
            return []
        elif c1==a1 and c1!=a2:
            return [a2]
        elif a1==a2:
            return [a1]
        else:
            return [a1,a2]
    elif c2==c3:
        if c1==a1 and c1==a2:
            return []
        elif c1==a1 and c1!=a2:
            return [a2]
        else:
            return [a1,a2]
    else:
        if c1==a1==a2:
            return [a1]
        else:
            return [a1,a2]

if len(s)<=2:
    print(s)
elif len(s)==3:
    if s[0]==s[1]==s[2]:
        print(s[:2])
    else:
        print(s)
else:
    i=2
    ans=[]
    ans.append(s[0])
    ans.append(s[1])
    while i<len(s)-1:
        c1=s[i]
        if i+1<=len(s)-1:
            c2=s[i+1]
        else:
            c2=''
        ans+=check(c1,c2,ans)
        i+=2
    print("".join(ans))