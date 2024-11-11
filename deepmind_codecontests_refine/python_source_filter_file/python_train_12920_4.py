for _ in range(int(input())):
    s=list(input())
    a=[]
    b=[]
    c=[]
    for i in range(len(s)):
        if s[i].isnumeric():
            a.append(i)
        else:
            if s[i].isupper():
                b.append(i)
            else:
                c.append(i)
    if len(a)==0:
        if len(b)>1:
            s[b[0]]='1'
        else:
            s[c[0]]='1'
        #print(s)
    if len(b)==0:
        if len(a)>1:
            s[a[0]]='A'
        else:
            s[c[0]]='A'
    if len(c)==0:
        if len(a)>1:
            s[a[0]]='a'
        else:
            s[b[0]]='a'
    print("".join(s))