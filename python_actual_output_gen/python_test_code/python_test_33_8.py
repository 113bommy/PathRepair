n=int(input())
i=1
x=["Howard","Sheldon","Leonard","Penny","Rajesh"]
b=5
while n>=b:
    n=n-b
    i=i+1
    b=5*(2**i)
print(x[((n-1+2**i)//2**i)%5])
