t = int(input().split()[0])
for case in range(t):
    s = input().split()[0]
##    check = [str(x) for x in range(9)]
##    for i in range(9):
##        for j in range(i+1,9):
##            check.append(str(i)+str(j))
##    best = 0
##    for subs in check:
##        if len(subs) == 1:
##            if s.count(subs) > best:
##                best = s.count(subs)
##        else:
##            if (s+s[0]).count(subs) * 2 > best:
##                best = (s+s[0]).count(subs) * 2
##    print(len(s)-best)
    best = len(s)
    for i in range(9):
        for j in range(9):
            if i == j:
                continue
            curr = 0
            foundFirst = True
            if s.count(str(i)) == 0:
                continue
            l = s.index(str(i))
            r = l+1
            while l < len(s):
                while r < len(s):
                    if foundFirst == False and s[r] == str(i):
                        foundFirst = True
                    if foundFirst == True and s[r] == str(j):
                        curr += 2
                        foundFirst = False
                        break
                    r += 1
                l = r
                r += 1
            if len(s)-curr < best:
                best = len(s)-curr
    for i in range(9):
        if len(s)-s.count(str(i)) < best:
            best = len(s)-s.count(str(i))
    print(best)
                        
