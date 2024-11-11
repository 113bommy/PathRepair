import math
n,x = [int(i) for i in input().split()]
c = 0
if x == 1:
    print(1)
else:
    for i in range(1,int(math.sqrt(x))+1):
    #print(i,x%i,int(x/i))
        if x%i == 0 and int(x/i) <= n:
       # print("Entered")
            #print(i)
            if i == int(math.sqrt(x)):
                c += 1
            else:
                c += 2
    print(c)