for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    likes = input()
    
    # new_arr = []
    # for i in range(n):
    #     new_arr.append([arr[i], likes[i]])
    # new_arr.sort()
    
    limit = 0
    for i in likes:
        if i == '1':
            limit += 1
    
    if limit == 0 or limit == n:
        for i in range(n):
            print(arr[i], end=" ")
        print("")
        continue
    else:
        acha, bura = [], []
        for i in range(n):
            if likes[i] == '1':
                acha.append([arr[i], i, likes[i]])
            else:
                bura.append([arr[i], i, likes[i]])
        acha.sort(key=lambda x : x[0])
        bura.sort(key=lambda x : x[0])
        a, b = len(acha), len(bura)
        for i in range(b):
            bura[i][0] = i+1
        for i in range(a):
            acha[i][0] = limit + i+1 
        acha += bura
        acha.sort(key = lambda x : x[1])
        for i in range(n):
            print(acha[i][0], end= " ")
        print("")
                
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        # acha, bura = [], []
        # for i in range(n):
        #     if likes[i] == "1":
        #         acha.append([arr[i], i])
        #     else:
        #         bura.append([arr[i], i])
        # acha.sort(key=lambda x : x[0], reverse=True)
        # bura.sort(key=lambda x : x[0], reverse=True)
        # # acha += bura
        # # acha.sort(key=lambda x : x[1])
        # # print(acha)
        # for i in range(len(acha)):
        #     if bura[i][0] > acha[i][0]:
        #         acha[i][0], bura[i][0] = bura[i][0], acha[i][0]
        # acha += bura
        # acha.sort(key=lambda x : x[1])
        # print(acha)
        
            
                
        