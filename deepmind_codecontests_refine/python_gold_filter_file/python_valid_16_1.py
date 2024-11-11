t = int(input())
while t!=0 :
    n = int(input())
    s = input()

    ss = sorted(s)

    #print(ss)

    c=0
    for i in range(len(s)):
        if(ss[i]!=s[i]):
            #print(ss[i], s[i])
            c+=1

    print(c)


    t-=1