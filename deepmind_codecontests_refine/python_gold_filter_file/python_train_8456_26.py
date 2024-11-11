t=int(input())
for i in range(t):
    z=1
    n= int(input())
    for i in range(1,n):
        z=z+2**i
        if(n%z==0):
            print(n//z)
            break
