def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def msi(): return map(str,input().split())
def li(): return list(mi())

t=ii()
for _ in range(t):
    n=ii()
    s=si()
    
    if s.count('0')==0:
        print(1,n-1,2,n)
        
    else:
        l,r=-1,-1
        
        for i in range(n//2):
            if s[i]=='0':
                l=i
                break
            
        for i in range(n//2,n):
            if s[i]=='0':
                r=i
                break
            
        if l!=-1:
            print(l+1,n,l+2,n)
            
        else:
            print(1,r+1,1,r)
                
    
    