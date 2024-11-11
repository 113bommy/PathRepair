n,q = map(int,input().split())

s1 = [1 for x in range(n+2)]
s2 = [1 for x in range(n+2)]
w = 0
for i in range(q):
    r,c = map(int,input().split())

    if r == 1:
        s1[c] = 1 - s1[c]
        
    else:
        s2[c] = 1 - s2[c]
            
    
    if r == 1:
        if s1[c] == 1:
            if s2[c-1] == 0 or s2[c] == 0:
                if s1[c-1] == 1:
                    w -= 1

            if s2[c] == 0 or s2[c+1] == 0:
                if s1[c+1] == 1:
                    w -= 1

        elif s1[c] == 0:
            if s2[c-1] == 0 or s2[c] == 0:
                if s1[c-1] == 1:
                    w += 1
                    
            if s2[c] == 0 or s2[c+1] == 0:
                if s1[c+1] == 1:
                    w += 1


    else:
        if s2[c] == 1:
            if s1[c-1] == 0 or s1[c] == 0:
                if s2[c-1] == 1:
                    w -= 1

            if s2[c] == 0 or s2[c+1] == 0:
                if s2[c+1] == 1:
                    w -= 1

        elif s2[c] == 0:
            if s1[c-1] == 0 or s1[c] == 0:
                if s2[c-1] == 1:
                    w += 1
                    
            if s1[c] == 0 or s1[c+1] == 0:
                if s2[c+1] == 1:
                    w += 1
                    
    if w == 0:
        print('Yes')

    else:
        print('No')