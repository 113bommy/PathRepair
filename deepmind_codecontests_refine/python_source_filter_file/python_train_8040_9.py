for i in range(int(input())):
    dic = {}
    n = int(input())
    arr = list(map(int,input().split()))
    same_room = False

    for k in range(len(arr)):        
        new_k = k+arr[k%n]
        if(new_k in dic):            
            same_room = True
            break
        else:
            dic[new_k] = 0
    
    if(same_room):
        print('NO')
    else:
        print('YES')