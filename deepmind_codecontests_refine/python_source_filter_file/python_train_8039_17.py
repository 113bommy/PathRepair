def solv():
    s=(input())
    a=''
    b=''
    p=0
    if len(s)==1:
        print(s)
        return
    q=len(s)-1
    while p<q and s[p]==s[q]:
        a+=s[p]
        b+=s[q]
        p+=1
        q-=1
    nw=''
    mx=0
    tm=''
    b=b[::-1]
    for n in range(p,q):
        tm+=s[n]
        if tm==tm[::-1]:
            nw=tm
    tm=''
    vv=''
    for n in range(q,p,-1):
        tm+=s[n]
        if tm==tm[::-1]:
            vv=tm
    res=nw if len(nw)>len(vv) else vv

    print(a+res+b)

for n in range(int(input())):
    solv()
