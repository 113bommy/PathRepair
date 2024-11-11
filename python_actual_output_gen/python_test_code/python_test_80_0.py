n=int(input())
def check(k):
    if k==1:
        return False
    elif k<4:
        return True
    for i in range(2,int(k**0.5) + 1):
        if k%i==0:
            return False
    return True

def solve(x,n):
    vis=[0]*(n+1)
    x-=n
    for i in range(1,n):
        print(i,(i+1))
    print(n,1)    
    mid=n//2    
    for i in range(x):
        print(1 + i,mid+ i)
        
        
    
    
for i in range(n,2000):
    if check(i):
        print(i)
        solve(i,n)
        break