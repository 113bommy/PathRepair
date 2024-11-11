n=input()
b=input()
if len(n)<len(b):
    print("need tree")
elif len(n)>len(b):
    if b in n:
        print("automaton")
    else:
        f=0
        c=list(set(b))
        count=0
        e=0
        s=""+n
        while len(s)>0:
            if b[e] in s:
                d=s.index(b[e])
                e+=1
                s=s[d+1::]+""
                count+=1
            else:
                break
            if count==len(b):
                break
        if count==len(b):
            print("automaton")
        else:
            for i in range(len(c)):
                d=n.count(c[i])
                e=b.count(c[i])
                if d>=e and e!=0:
                    continue
                else:
                    f=1
                    break
            if f==1:
                print("need tree")
            else:
                print("both")
elif len(n)==len(b):
    f=0
    c=list(set(b))
    for i in range(len(c)):
        d=n.count(c[i])
        e=b.count(c[i])
        if d>=e and e!=0:
            continue
        else:
            f=1
            break
    if f==1:
        print("need tree")
    else:
        print("array")