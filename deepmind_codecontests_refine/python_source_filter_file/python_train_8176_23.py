s=input()
def solve(s):
    if len(s)<26:
        return [-1]
    for i in range(len(s)-25):
        tempset=set()
        q=0
        for j in range(i,i+26):
            if s[j]=="?":
                q+=1
            else:
                tempset.add(s[j])
        if q+len(tempset)==26:
            return [1,i,i+26]
    else:
        return [-1]

ans=solve(s)
if ans[0]==1:
    start,end=ans[1],ans[2]
    left=set()
    for i in range(97,97+26):
        left.add(chr(i).upper())
    for i in range(start,end):
        if s[i] in left:
            left.remove(s[i])
    ans=""
    for i in range(start):
        if s[i]=="?":
            ans+="A"
        else:
            ans+=s[i]
    for i in range(start,end):
        if s[i]=="?":
            ans+=left.pop()
        else:
            ans+=s[i]
    for i in range(end,len(s)):
        if s[i]=="?":
            ans=="A"
        else:
            ans+=s[i]
    print(ans)

else:
    print(-1)
