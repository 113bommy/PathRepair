def twelve(s):
    dellst=[]
    i=0
    while i<=len(s)-3:
        if s[i:i+3]=='one':
            dellst+=[i+2]
            i+=3
        elif s[i:i+3]=='two':
            if i<=len(s)-5:
                if s[i:i+5]=='twone':
                    dellst+=[i+3]
                    i+=5
                else:
                    dellst+=[i+2]
                    i+=3
            else:
                dellst+=[i+2]
                i+=3
        else:
            i+=1
    return dellst



m=int(input())
for i in range(m):
    s=input()
    k=twelve(s)
    print(len(k))
    print(*k)
