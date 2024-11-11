n,k=map(int,input().split())


if(k>2*n-1):
    print(0)
elif(k<=1):
    print(0)
elif(n>=k):
    print(k//2)
else:
    print((k+1)//2-(k-n))
    
    