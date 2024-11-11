t=int(input())
for q in range(t):
    s=int(input())
    ap=input()
    pgroups=[]
    for x in range(s-1):
        try:
            if ap[x]=='A' and ap[x+1]=='P':
                a2=ap[x+1:].index('A')
                pgroups.append(a2)
        except:
            pgroups.append(s-1-x)
    if len(pgroups)==0:
        print(0)
    else:
        print(max(pgroups))