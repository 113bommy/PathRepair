import math
for _ in range(int(input())):
    x=int(input())
    result=x-1
    sqr=math.floor(math.sqrt(x))+1
    for i in range(2,sqr):
        if(x%i==0):
            result=x/i
            break
    print(result,x-result)