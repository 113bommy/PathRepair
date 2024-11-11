for iii in range(int(input())):
    n = int(input())
    lst = list(map(int, input().split()))
    
    if n == 1:
        if lst[0] == 1:
            print(2, 1)
        else:
            print(1, 2)
        continue
        
    if lst[-1] == 0:
        for i in range(n+1):
            print(i+1, end=" ")
        print()                
        continue
    
    tmp = -1

    for i in range(n-1):
        if lst[i] == 0 and lst[i-1] == 1:
            tmp = i
            break
            
    if tmp != -1:
        for i in range(n):
            print(i+1, end=" ")
            if i == tmp:
                print(n+1, end=" ")
        print()
        continue
            
    if sum(lst) == n:
        print(n+1, end=" ")
        for i in range(n):
            print(i+1, end=" ")
        print()
        continue
    
    
    print(-1)
        