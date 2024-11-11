s=input()
t=input()
if(len(s)<len(t)):
    print("need tree")
elif(len(s)==len(t)):
    a=dict()
    b=dict()
    for i in range(len(s)):
        if s[i] not in a:
            a.update({s[i]:s.count(s[i])})
    for i in range(len(t)):
        if t[i] not in b:
            b.update({t[i]:t.count(t[i])})
    if(len(a)!=len(b)):
        print("need tree")
    else:
        x=0
        for i in a:
            if i in b:
                if a[i]!=b[i]:
                    x=1
                    break
            else:
                x=1
                break
        if(x):
            print("need tree")
        else:
            print("array")
else:
    j=h=0
    for i in range(len(t)):
        while j<len(s):
            if(s[j]==t[i]):
                h+=1
                break
            j+=1
        j+=1
    if(h==len(t)):
        print("automaton")
    else:
        a=dict()
        b=dict()
        for i in range(len(s)):
            if s[i] not in a:
                a.update({s[i]:s.count(s[i])})
        for i in range(len(t)):
            if t[i] not in b:
                b.update({t[i]:t.count(t[i])})
        x=0
        for i in b:
            if i in a:
                if(a[i]<b[i]):
                    x=1
                    break
            else:
                x=1
                break
        if(x):
            print("need tree")
        else:
            print("both")