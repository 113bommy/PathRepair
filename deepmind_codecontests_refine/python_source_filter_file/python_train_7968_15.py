n = int(input())
if(n == 1):
    print(-1)
else:
    if(n % 2):
        print(n*n//2,n*n//2 + 1)
    else:
        print(n*n//4 - 1,n*n//4 + 1)
    

