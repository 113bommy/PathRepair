s=input()
t=input()
e=""
r=False
for i in range(len(s)):
    if s[i]==t[i]:
        e+=s[i]
        continue
    elif (ord(t[i])-ord(s[i]))>1:
        r=True
        e+=chr(ord(s[i])+1)
        if i<len(s)-1:
            e+=s[i+1:]
        break
    else:
        r=True
        if i==len(s)-1:
            r=False
        q=s[i+1:]
        p=t[i+1:]
        if q=='z'*(len(s)-i-1) and p=='a'*(len(s)-i-1):
            r=False
        if q!='z'*(len(s)-i-1):
            e += s[i]
            for o in range(len(q)-1,-1,-1):
                if q[o]!='z':

                    e+=q[:o]+chr(ord(q[o])+1)+q[o+1:]
                    break
        elif p!='a'*(len(t)-i-1):
            e += t[i]
            for o in range(len(p)-1,-1,-1):
                if q[o]!='a':
                    e+=p[:o]+chr(ord(p[o])-1)+p[o+1:]
                    break
        break


if r:
    print(e)
else:
    print("No such string")