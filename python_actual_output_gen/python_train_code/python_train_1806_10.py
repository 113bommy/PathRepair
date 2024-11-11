def ans(n):
    if(n==0 or n>11):
        return 0
    elif(1<=n<10) or (n==11):
        return 4
    else:
        return 15
    
n=int(input())
n-=10
print(ans(n))