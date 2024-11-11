def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def msi(): return map(str,input().split())
def li(): return list(mi())

t=ii()
for _ in range(t):
    s=si()
    ans=20
    
    for i in range(40):
        res=str(2**i)
        i,j=0,0
        
        while i<len(s) and j<len(res):
            if s[i]==res[j]:
                j+=1
                
            i+=1
            
        ans=min(ans,len(s)+len(res)-2*j)
        
    print(ans)
    
    