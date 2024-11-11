t=int(input())
for ii in range(t):
    s=input().rstrip()
    c=['a','b','c']
    s=[ i for i in s]
    if len(s)==1:
        if s[0]!='?':
            print(''.join(s))
        else:
            print('a')
        continue
    elif len(s)==2:
        if s[0]=='?' and s[1]=='?':
            print('ab')
        elif s[0]=='?'  and s[1]!='?':
            c=['a','b','c']
            for i in c:
                if i!=s[1]:
                    print(i+s[1])
                    break
        elif s[0]!='?'  and [1]=='?':
            c=['a','b','c']
            for i in c:
                if i!=s[0]:
                    print(s[0]+i)
                    break
        else:
            print(''.join(s))
        continue

                    
        
        
    for i in range(1,len(s)-1):
        c=['a','b','c']
        if s[i]=='?':
            if s[i-1]==s[i+1]:
                if s[i-1] in c:
                    c.pop(c.index(s[i-1]))
                s[i]=c[0]
            else:
                if s[i-1] in c:
                    c.pop(c.index(s[i-1]))
                if s[i+1] in c:
                    c.pop(c.index(s[i+1]))
                s[i]=c[0]
    if s[-1]=='?':
        c=['a','b','c']
        for i in c:
            if i!=s[-2]:
                s[-1]=i
                break
    if s[0]=='?':
        c=['a','b','c']
        for i in c:
            if i!=s[1]:
                s[0]=i
                break
    flag=0
    for i in range(1,len(s)):
        if s[i-1]==s[i]:
            flag=1
            break
    if flag==1:
        print(-1)
    else:
        print(''.join(s))
        
    
            
            
            
        
        