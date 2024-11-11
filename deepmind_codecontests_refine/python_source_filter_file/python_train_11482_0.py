for iiii in range(int(input())):
    n = int(input())
    lst = list(map(int, input().split()))
    k = 0
    tmp = lst[0]
    two = 0
    answer = set()

    for i in range(1, n):
        if lst[i] != tmp:
            answer.add((1, i + 1))
            k+=1
            two = i+1
           # print('two', two)
            
    if k == 0:
        print("NO")
        continue
    else:
        print("YES")
        for i, j in answer:
            print(i, j)
    
    for i in range(2, n):
        if lst[i] == lst[0]:
            print(two, i+1)
            
    
        
    