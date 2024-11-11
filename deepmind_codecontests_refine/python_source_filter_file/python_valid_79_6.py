t=int(input())
while t:
    k=int(input())
    s=input()
    comp=[1,4,6,8,9]
    flag=0
    comp2=[22,25,27,35,72,77,52,32,55,75,33,57]
    for i in s:
        i=int(i)
        if i in comp:
            flag=1
            I=str(i)
            print(len(I))
            print(i)
            break
    if flag==0:
        for i in range(len(s)):
            for j in range(i+1,len(s)):
                k=s[i]+s[j]
                k=int(k)
                if k in comp2:
                    K=str(k)
                    print(len(K))
                    print(k)
                    break
                else:
                    continue
            break


    t -= 1