
t=int(input())
for _ in range(t):
    n=int(input())
    for i in range(2,n):
        if(n%(int(pow(2,i))-1)==0):
            print(n//(int(pow(2,i))-1))
            break