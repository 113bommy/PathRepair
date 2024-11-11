def entangle(a):
    s=list(a)
    c=list()
    if len(s)==1:
        return 'No'
    else:
        c.append(s[0])
    i=1
    while i < len(c):
        if len(c)>0:
            if s[i]==c[len(c)-1]:
                c.pop()
            else:
                c.append(s[i])
        else:
            c.append(s[i])
        i=i+1
    if len(c)==0:
        return 'Yes'
    else:
        return 'No'

s0=input()
print(entangle(s0))