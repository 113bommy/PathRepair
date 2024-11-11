for i in range(int(input())):
    n= int(input())
    k = 1
    for i in range(n):
        k+=1
        if(k%3==0):
           k+=1
        if(k%10==3):
            k+=1
        if(k%3==0):
           k+=1
    print(k)