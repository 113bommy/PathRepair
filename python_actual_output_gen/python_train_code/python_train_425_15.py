s=input()
if len(s)%2==1:
    print(-1)
else:
    p=0
    kp=0
    w=0
    kw=0
    for i in range(len(s)):
        if s[i]=='R':
            p+=1
            kp+=1
        elif s[i]=='L':
            p-=1
            kp+=1
        elif s[i]=='U':
            w+=1
            kw+=1
        else:
            w-=1
            kw+=1
    print(abs(p)//2+abs(w)//2)