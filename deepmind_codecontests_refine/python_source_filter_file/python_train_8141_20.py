from collections import *

for _ in range(int(input())):
    
    s = input()
    s += "yy"
    d = defaultdict(lambda : 0)
    a = list()
    
    s1 = 0
    
    for i in range(len(s)):
        # print(a,s)
        if(s[i] == "o"):
            if(s1 == 0 or s1 == 1):
                s1 = 1
            else:
                s1 = 0
        elif(s[i] == "n"):
            if(s1 == 1):
                s1 = 2
            else:
                s1 = 0
        elif(s[i] == "e"):
            if(s1 == 2):
                s1 = 3
            else:
                s1 = 0
        else:
            s1 = 0
                
        if(s1 == 3):
            i1 = i - 4
            i2 = i - 3
            
            if(s[i1] == "t" and s[i2] == "w"):
                d[i-2] = 1
                a.append(i-1)
            else:
                d[i-1] = 1
                a.append(i)
            s1 = 0
                
    # print(a)
    s1 = 0
    for i in range(len(s)):
        if(d[i] == 0):
            # print(s1,i+1)
            if(s[i] == "t"):
                if(s1 == 0 or s1 == 1):
                    s1 = 1
                else:
                    s1 = 0
            elif(s[i] == "w"):
                if(s1 == 1):
                    s1 = 2
                else:
                    s1 = 0
            elif(s[i] == "o"):
                if(s1 == 2):
                    s1 = 3
                else:
                    s1 = 0
            else:
                s1 = 0
                    
            if(s1 == 3):
                d[i-1] = 1
                a.append(i)
                s1 = 0
                
    print(len(a))
    print(*a)
