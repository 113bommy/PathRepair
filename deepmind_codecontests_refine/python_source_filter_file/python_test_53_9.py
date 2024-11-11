import math
for _ in range(int(input())):
    n, c = map(str,input().split())
    n = int(n)
    s = input()
    at = []
    for i in range(n):
        if(s[i] == c):
            at.append(i+1)
    if(len(at) == 0):
        print(2)
        print(n, n-1)
    elif(len(at) == n):
        print(0)
    elif(at[-1] == n):
        print(1)
        print(n)
    elif(at[-1] == n-1):
        print(1)
        print(n-1)
    else:
        done = False
        for i in range(2, n+1):
            yes = True
            for j in range(i, n+1, i):
                if(s[i-1] != c):
                    yes = False
                    break
            if(yes):
                done = True
                print(1)
                print(i)
                break
        if(not done):
            print(2)
            print(n, n-1)