import math
t=int(input())
while(t!=0):

    n,d = map(int, input().split())
    a = list(map(int, input().split()))

    for i in range(1, n):
        #print(a)
        if(a[i]!=0):
            if(i*a[i]<=d):
                a[0] = a[0] + a[i]
                d = d - a[i]*i
                a[i]=0
            
            else:
                temp = math.floor(d/i)
                print("tmep", temp)
                a[0] = a[0] + temp
                break
    print(a[0])
    
    
    t=t-1
