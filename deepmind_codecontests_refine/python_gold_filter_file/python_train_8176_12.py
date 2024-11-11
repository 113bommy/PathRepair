a = list(input())
A=set()
cou = [0] * 26
if len(a) < 26:
    print(-1)
else:
   
    s = 0
    per = -1
    for j in range(26):
        if a[j] != '?':
            A.add(a[j])
            cou[ord(a[j]) - 65] +=1
        else:
            s+=1
    if len(A) + s == 26:
        per = 0
    
    for j in range(0, len(a) - 26):
        if a[j] == '?':
            s-= 1
            
        else:
            cou[ord(a[j]) - 65] -= 1
            if cou[ord(a[j]) - 65] == 0:
                A.discard(a[j])
        if a[j+26] != '?':
                
            A.add(a[j+26])
            cou[ord(a[j+26]) - 65] +=1
        else:
            s += 1        
        if len(A) + s == 26:
            per = j + 1
            break
    if per == -1:
        print(-1)
    else:
        A = set('ABCDEFGHIJKLMNOPQRZTUVWXYS')
        
        for j in range(per, per + 26):
            if a[j] != '?':
                A.discard(a[j])
        for j in range(per, per + 26):
            if a[j] == '?':
                a[j] = A.pop()
        for j in range(len(a)):
            if a[j] == '?':
                a[j] = 'A'
        print(''.join(a))
        