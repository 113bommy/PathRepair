s=input()
i=0
j=len(s)-1
m=len(s)//2
if s.count("a")>=m:
    print("a"*m)
elif s.count("b")>=m:
    print("b"*m)
elif s.count("c")>=m:
    print("c"*m)
else:
    i=0
    j=len(s)-1
    r=[]
    while i<j:
        if s[i]==s[j]:
            r.append(s[i])
            i+=1
            j-=1
        elif s[i]==s[j-1]:
            r.append(s[i])
            i+=1
            j-=2
        elif s[i+1]==s[j]:
            r.append(s[j])
            i+=2
            j-=1
        else:
            r.append(s[i+1])
            i+=2
            j-=2
    if j==i:
        x=r+[s[i]]+r[::-1]
    else:
        x=r+r[::-1]
    if len(x)<m:
        print("IMPOSSIBLE")
    else:
        print("".join(x))
            