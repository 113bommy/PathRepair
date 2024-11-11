from collections import defaultdict as DD
import sys
MOD=pow(10,9)+7

def IN(f=0):
    if f==0:
        return ( [int(i) for i in sys.stdin.readline().split()] )
    else:
        return ( int(sys.stdin.readline()) )
def fnx(e,r):
    t=['a','b','c']
    t.remove(e)
    t.remove(r)
    return(t[0])

def fnx1(e):
    t=['a','b','c']
    t.remove(e)
    return(t)

def F(q,w,n):
    ans = "-1"
    if q==w:
        #aa aa
        if q[0]==q[1]:
            t=fnx1(q[0])
            #print(t)
            ans = (q[0]+t[0])*n + t[1]*n
            return(ans)
        #ab ab
        else:
            ans = q[0]*n + fnx(q[0],q[1])*n + q[1]*n
            return(ans)
            
            
    else:
        if q[0]==q[1] or w[0]==w[1]:
            #aa bb
            if q[0]==q[1] and w[0]==w[1]:
                ans = (q[0]+w[0])*n + fnx(q[0],w[0])*n
                return(ans)
            if q[0]!=q[1]:
                w,q=q,w
            #aa ab
            if q[0]==w[0] and q[0]!=w[1]:
                ans = (q[0]+fnx(q[0],w[1]))*n + w[1]
                return(ans)
            #aa ba
            if q[0]==w[1] and q[0]!=w[0]:
                ans = (q[0]+fnx(q[0],w[0]))*n + w[0]
                return(ans)
            #aa bc        
            if q[0]!=w[0] and q[0]!=w[1]:
                ans = (q[0] + w[1])*n + w[0]*n
                return(ans)
        else:
            #ab cb
            if q[0]!=w[1] and q[1]==w[0]:
                ans = (q[0] + w[1])*n + w[0]*n
                return(ans)
            #ab cb
            if q[0]!=w[0] and q[1]==w[1]:
                ans = q[1]*n + q[0]*n + w[0]*n
                return(ans)
            #ab ba
            if q[0]==w[1] and q[1]==w[0]:
                ans = q[0]*n + fnx(q[0],q[1])*n + q[1]*n
                return(ans)
            #ab ac
            if q[0]==w[0] and q[1]!=w[1]:
                ans = q[1]*n + w[1]*n + q[0]*n
                return(ans)
            #ab ca
            if q[0]==w[1] and q[1]!=w[0]:
                ans = q[1]*n + q[0]*n + w[0]*n
                return(ans)
                
    return(ans)
        
        
        
#while(1):
if (1):
    n=IN(1)
    q=input()
    w=input()
    s=F(q,w,n)
    if s!='-1':
        print("YES")
        print(s)
    else:
        print(1/0)
        

        
        
    
    
    
