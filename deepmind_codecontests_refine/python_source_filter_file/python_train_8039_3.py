for _ in range(int(input())):
    s=input()
    n=len(s)-1
    flag=0
    for i in range(len(s)//2):
        if s[i]==s[n]:
            n=n-1
        else:
            flag=1
            break
    if flag==1:
        prefix=s[0:i]
        suffix=s[n+1:len(s)]
        x=''
        y=''
        for j in range(n,i+1,-1):
            temp=s[i:j+1]
            if temp==temp[::-1]:
                x=temp
                break
            else:
                continue
        for k in range(len(prefix),n+1):
            temp1=s[k:n+1]
            if temp1==temp1[::-1]:
                y=temp1
                break
            else:
                continue
        #print(x,y)
        if len(x)>len(y):
            print(prefix+x+suffix)
        else:
            print(prefix+y+suffix)
            
        
    else:
        print(s)

        