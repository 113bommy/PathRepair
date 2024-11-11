from collections import  Counter
for _ in range(int(input())):
    n,x = map(int,input().split())
    l = list(map(int,input().split()))
    k = 0
    c = 0
    for i in l:
        k+=(x-i)
        if i == x:
            c+=1
    if c == n:
        print(0)
    else:
        if c == n-1:
            print(1)
        else:
            if k == 0:
                print(1)
            else:
                print(2)
    
    
