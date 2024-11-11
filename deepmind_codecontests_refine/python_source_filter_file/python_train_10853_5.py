#numbers game

def solve(n):
    if(n==1):
        return False
    if(n%2!=0):
        return True
    ans=False
    if(n-1==1):
        return True
    l=list()
    i=2
    while(i*i<=n):
        if(n%i==0):
            l.append(i)
            if(n//i!=i):
                l.append(n//i)
        i+=1
    for i in l:
        if(i%2!=0):
            if(not solve(n//i)):
                return True
            break
    
    return False
                
                

if __name__=="__main__": 
    t=int(input())
    for i in range(t):
        n=int(input())
        f=solve(n)
        if(f):
            print('Ashishgup')
        else:
            print('FastestFinger')
