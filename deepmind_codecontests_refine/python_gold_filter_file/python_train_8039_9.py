t=int(input())
for _ in range(t):
    s=str(input())
    p1=0
    p2=len(s)-1
    res = ''
    if(len(s)==1):
        print(s)
    else:
        while(p1<p2):
            if(s[p1]==s[p2]):
                p1=p1+1
                p2=p2-1
            else:
                break
        s1= s[0:p1]
        s2=s[p2+1:len(s)]
        part = s[p1:p2 + 1]
        for i in range(len(part)):
            if (part[0:i + 1][::-1] == part[0:i + 1]):
                if(len(part[0:i + 1]) > len(res)):
                    res = part[0:i + 1]
        part = part[::-1]
        for i in range(len(part)):
            if (part[0:i + 1][::-1] == part[0:i + 1]):
                if(len(part[0:i + 1]) > len(res)):
                    res = part[0:i + 1]
        print(s1 + res,end="")
        print(s2)