cases = int(input())

for i in range(cases):
    n = int(input())
    s = input()
    count = 0

    for a in range(len(s)-6):
        ele = s[a]
        temp = ele
        for b in s[a+1:a+7]:
            temp += b
            if temp == 'abacaba':
                count += 1
    if count >1:
        print ("NO")
    
    elif s.count('?') == len(s): #all question marks in string
        print ("YES")
        ans = 'abacaba'
        rest = len(s) - 7
        ans += rest*'d'
        print (ans)
    
    else:   
        if count == 1: #there is one substring in string
            if '?' not in s:
                print ("YES")
                print (s)
            else:
                s = list(s)
                for c in range(len(s)):
                    ele = s[c]
                    if ele == '?':
                        s[c] = 'd'
                print("YES")
                print (''.join(s))
        elif count == 0 and '?' in s:
            target = 'abacaba'
            for d in range(len(s)-6):
                possible = False
                scopy = list(s)
                ele = scopy[d]
                temp = ele
                for e in scopy[d+1:d+7]:
                    temp += e
                #double nested loops
                #still inside second nested loop
                if '?' in temp:
                    #inside first loop
                    temp = list(temp)
                    target = list(target)
                    arr = []
                    for j in range(7):
                        ele1 = temp[j]
                        ele2 = target[j]
                        if ele1!= ele2 and ele1 == '?':
                            temp[j] = ele2
                            arr.append(j)
                    if temp == target: #possible to replace ?  to form substring
                        possible = True
                        for f in arr:
                            scopy[d+f] = temp[f]
                    count2 = 0
                    if possible:
                        for a in range(len(scopy)-6):
                            ele3 = scopy[a]
                            temp2 = ele3
                            for b in scopy[a+1:a+7]:
                                temp2 += b
                                if temp2 == 'abacaba':
                                    count2 += 1
                        if count2 != 1:
                                possible = False
                        elif count2 == 1:
                            possible = True
                            print ("YES")      
                            for s2 in range(len(scopy)):
                                beta = scopy[s2]
                                if beta == '?':                                        
                                    scopy[s2] = 'd'
                            print (''.join(scopy))
                            break
                        

            if not possible:
                print ("NO")
        elif count == 0 and '?' not in s:
            print("NO")
                        
                

