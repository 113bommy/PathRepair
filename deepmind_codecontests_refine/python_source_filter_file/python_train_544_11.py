for _ in range(int(input())):
    s=input()
    oc,zc=0,0
    for i in s:
        if i=='0':
            zc+=1
        else:
            oc+=1
    m=min(zc,oc)
    if m%2==0:
        print("DA")
    else:
        print("NET")
    