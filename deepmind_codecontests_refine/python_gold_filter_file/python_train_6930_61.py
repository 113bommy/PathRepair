def call(x):
    for i in range(2,int(x**0.5)+1):
        if x %i==0:
            return 1
    return -1
    
n=int(input())
for i in range(1,n+10):
    #print(i)
    
    f=call(n*i+1)
    #print(f)
    if f==1:
        print(i)
        break

