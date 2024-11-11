for _ in range(int(input())):
    s=input()
    t=input()
    d=sorted(s)
    flag=1
    for x in t:
        if x not in d:
            print(''.join(d))
            flag=0
            break
    if flag:
        ans=""
        cnt=0
        i=-1
        if t[1]=='b':
            for x in range(len(s)):
                if d[x]=='c':
                    cnt+=1
                if d[x]=='a':
                    i=x
            y=""      
            for l in range(cnt):
                y+='c'
                        
            for x in range(len(s)):
                if x==(i+1):
                    ans+=y
                if d[x]=='c':
                    continue
                else:
                    ans+=d[x]
            print(ans)
                
        else:
            print("".join(d))
                
                
                
