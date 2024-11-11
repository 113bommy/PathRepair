n=int(input())
for _ in range(1):
    s=input().rstrip()
    f1=True
    fl1=False
    for i in range(1,len(s)):
        if s[i] is not "?" and s[i] is s[i-1]: 
            f1=False
            break
    if f1:
        #print("abc")
        if s[0] is "?" or s[len(s)-1] is "?":
            print("Yes")
            fl1=False
        elif s.count("?")==0:
            print("Yes")
            fl1=False
        else:
            f=False
            last=-1 
            for i in range(len(s)):
                if s[i] is "?":
                    if not f:
                        last=i
                        f=True
                else:
                    if f:
                        l=i-last
                        if l>1:
                            print("Yes")
                            fl1=False
                            break
                        else:
                            if s[last-1] is s[i]:
                                print("Yes")
                                fl1=False
                                break
                            else:
                                fl1=True
                                #print("No")
                                #break
                            f=False
        
                    
    else:
        print("No")
        
    if fl1:
        print("No")