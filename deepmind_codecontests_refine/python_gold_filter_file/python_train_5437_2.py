n,m = list(map(int,input().split()))



def c(n,r):
    res =1
    
    if r>n-r:
        r=n-r
    for i in range(0,r):
        res = res*(n-i)
        res = res//(i+1)
    
    return res
    
ans = c(n+2*m-1,2*m)%1000000007

print(ans)