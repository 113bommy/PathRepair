for _ in range(int(input())):
    s = input()
    p=0
    s1=list()
    for i in s:
        if i == "1":
            p+=1
        else:
            if p > 0:
                s1.append(p)
            p=0
    s1.append(p)
    s1.sort(reverse=True)
    #print(s1)
    a,b=0,0
    for i in range(len(s1)):
        if s1[i] & 1:
            b+=s1[i]
        else:
            a+=s1[i]
    print(a)