s=input()
c=0
d=9
if(len(s)>1):
    for i in range(len(s)-1):
        if(s[i]!=s[i+1]):

            c=c+1
            d=0

        else:
            d=d+1
            if(d==5):
                d=0
                c=c+1
    if(s[-1]==s[-2] and d!=5):
        c=c+1
    elif(s[-1]!=s[-2]):
        c=c+1
    print(c)
else:
    print(1)
    