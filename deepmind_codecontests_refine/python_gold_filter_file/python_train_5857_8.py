for tt in range(int(input())):
    n,r=map(int,input().split())
    
    if(r<n):
        print(((1+r)*(r-1+1))//2)
    else:
        print(1+((1+(n-1))*(n-1))//2)