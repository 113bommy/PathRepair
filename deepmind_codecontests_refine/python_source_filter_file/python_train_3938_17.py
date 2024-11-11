s = [int(i) for i in input()]
    
if s[0] == 0 or s[-1] == 1 :
    print(-1)
    
else :
    s.pop()
    if s != s[::-1] :
        print(-1)
        
    else :
        org = 1
        for i in range((len(s) + 1) // 2) :
            if s[i] == 1 :
                for j in range(org + 1, i + 3) :
                    print(i + 1, j)
                org = i + 2
        for i in range(org + 1, len(s) + 2) :
            print(org, i)