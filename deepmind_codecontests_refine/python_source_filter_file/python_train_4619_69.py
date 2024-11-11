def f():
    n = int(input())
    counter = 0
    lst = []
    for i in range(0,n):
        c = 0
        lst = input().split(" ")
        for j in range(0,3):
            if(lst[j] == 1):
                c+=1
        if(c >= 2):
            counter+=1
            
            
    print(counter)
    
f()
            