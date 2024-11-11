for i in range(int(input())):
    a=input()
    a+='R'
    r=-1
    l=[]
    for j in range(1,len(a)):
        if a[j]=='R':
            l.append(j-r)
            r=j
    print(max(l))