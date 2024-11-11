def calcSum(first):
    global m
    s = m[first]
    k = 1
    for i in range(first + 1, len(m)):
        yes = True
        for j in range(first, i):
            if m[j] % m[i] == 0:
                yes = False
                break
        if yes:
            s += m[i]
            k += 1
            if k == 3: break
    return s
    

import sys
nnn = int(input())
for _ in range(nnn):
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    if n == 1:
        print(a[0])
        continue
    if n == 2:
        if a[0]%a[1] == 0 or a[1]%a[0] == 0:
            print(max(a))
        else:
            print(sum(a))
        continue
    a.sort(reverse = True)
    m = [a[0]]
    for i in range(1, len(a)):
        if a[i] == a[i-1]: continue
        yes = True
        for j in range(1, len(m)):
            if j % a[i] == 0:
                yes = False
                break
        if yes:
            m.append(a[i])
            if len(m) >= 10:
                break

##    print(m)
            
    s1 = calcSum(0)
    if len(m) > 1:
        s2 = calcSum(1)
    else:
        s2 = 0

    s = max(s1, s2)

    print (s)
##    if nnn == 16383:
##        if _>300:
##            print(m, ' - ', a, '-', s)
##    else:
##        print(s)

        
        
