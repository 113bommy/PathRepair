
arr =[]
test_cases =int(input(''))
for x in range(test_cases):
    a=[]
    a = list(map(int,input().split()))
    arr.append(a)
for t in range(test_cases):
    x=arr[t][0]
    y=arr[t][1]
    a=arr[t][2]
    b=arr[t][3]

    if abs(y-x)%(a+b)==0:
        if abs(y-x)%(a+b)==0:
            print((y-x)/(a+b))
    else :
        print("-1")
    

