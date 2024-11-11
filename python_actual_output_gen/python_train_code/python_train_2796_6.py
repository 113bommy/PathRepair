T = int(input())
for i in range(T):
    s = [x for x in input().strip()]
    p1 = 0
    r = 0
    A = []
    while(p1<len(s)-2):
        # print(p1,s[p1])
        if p1<len(s)-5 and s[p1:p1+5]==['t','w','o','n','e']:
            r+=1
            A.append(str(p1+3))
            p1+=5
        elif s[p1:p1+3]==['t','w','o']:
            r+=1
            A.append(str(p1+2))
            p1+=3
        elif s[p1:p1+3]==['o','n','e']:
            r+=1
            A.append(str(p1+2))
            p1+=3
        else:
            p1+=1
    print(r)
    print(' '.join(A))