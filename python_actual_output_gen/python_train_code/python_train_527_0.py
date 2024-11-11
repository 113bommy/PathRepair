t=int(input())
for _ in range(t):
    s=input()
    s=list(s)
    for i in range(len(s)):
        
        if(i==0):
            if(s[i]=='a'):
                s[i]='b'
                continue
            else:
                print("imin")
                s[i]='a'
                continue
        if(i%2==0 and i!=0):
            if(s[i]!='a'):
                s[i]='a'
                continue
            else:
                s[i]='b'
                continue
        else:
            if(s[i]!='z'):
                s[i]='z'
                continue
            else:
                s[i]='y'
                continue
    print(*s,sep="")
