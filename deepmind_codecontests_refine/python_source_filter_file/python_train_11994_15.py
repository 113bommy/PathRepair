t = int(input())

for i in range(t):
    a = input()
    s = list(a)

    
    ans = 1
    j = 1
    
    
    if a == '?':
        print('a')
        continue
    if len(s) == 1:
        print(a)
    if len(s) == 2:
        if s[0] == s[1]:
            if s[1]!='?':
                ans = 0
            else:
                s[1] ='a'
                s[0] ='b'
                
        else:
            if s[0] =='?':
                if s[1] == 'b' or s[1] == 'c':
                    s[0] = 'a'
                if s[1] == 'a':
                    s[0] = 'b'
                    
            if s[1] =='?':
                if s[0] == 'b' or s[0] == 'c':
                    s[1] = 'a'
                if s[0] == 'a':
                    s[1] = 'b'
    
    if s[0] == '?':
        if s[1] == '?':
            s[0] = 'a'
            
        if s[1] == 'b' or s[1] == 'a':
            s[0] = 'c'
        else:
            s[0] = 'a'        
        
    while j < len(s) - 1:
        if s[j] == s[j - 1] and s[j] != '?' or s[j] == s[j + 1] and s[j] != '?':
            ans = 0
            break
        if s[j] =='?':
            '''if s[j - 1] == '?': #and s[j + 1] != 'a':
                s[j - 1] = 'a'''
            if s[j - 1] == 'a':
                if s[j + 1] =='b':
                    s[j] = 'c'
                if s[j + 1] == 'a' or s[j + 1] == 'b':
                    s[j] = 'c'
                if s[j + 1] == '?':
                    s[j] = 'b'
                        
                    
            if s[j - 1] == 'b':
                if s[j + 1] =='c':
                    s[j] = 'a'
                if s[j + 1] == 'a' or s[j + 1] == 'b':
                    s[j] = 'c'
                if s[j + 1] == '?':
                    s[j] = 'c'
                    
                    
            if s[j - 1] == 'c':
                if s[j + 1] =='a':
                    s[j] = 'b'
                if s[j + 1] == 'c' or s[j + 1] == 'b':
                    s[j] = 'a'
                if s[j + 1] == '?':
                    s[j] = 'a'
                    
            
        j += 1
    tmp = len(s)
    
    if s[tmp - 1] == '?':
        if s[tmp - 2] == 'b' or s[tmp - 2] == 'a':
            s[tmp - 1] = 'c'
        else:
            s[tmp - 1] = 'a'
    if ans:
        for k in range(len(s)):
            if k == len(s) - 1:
                print(s[k])
                continue
            print(s[k], end = '')
    else:
        print(-1)
                    
                
        