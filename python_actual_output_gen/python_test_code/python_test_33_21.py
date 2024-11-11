n=int(input())
a=["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]
if(n>=5):
    while(n>=5):
        n-=5
        n=n//2
    
    print(a[n])
else:
    print(a[n-1])
