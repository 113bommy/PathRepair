arr=[]

test_cases=int(input('>'))
for x in range(test_cases):
    
    a=[]
    a = list(map(int,input().split()))
    
    arr.append(a)







for y in range(test_cases):
    x1=arr[y][0]
    y1=arr[y][1]
    a=arr[y][2]
    b=arr[y][3]

    aa1=y1-x1
    bb1=a+b

    if aa1 % bb1==0:
        print(int(aa1/bb1))
    
    else:
        print(-1)
    
    
    
    
    
    
    
