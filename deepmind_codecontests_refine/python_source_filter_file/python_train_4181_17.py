t=int(input())
while t>0:
        s=sorted(input())
        if len(set(s))==len(s):
            if len(s)==2:
                if ord(s[1])-ord(s[0])==1:
                    print("YES")
                else:
                    print("NO")
            else:
                for i in range(1,len(s)-1):
                    if ord(s[i+1])-ord(s[i])==1:
                        pass
                    else:
                        print("NO")
                        break
                else:
                    print("YES")
            
        else:
            print("NO")
        t -= 1