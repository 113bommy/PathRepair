import sys
def data():
    return sys.stdin.readline().strip()
    
def sp(): return map(int, data().split())    
def l(): return list(sp())

def ans(pl,n,m):    
    temp=sorted(pl)
    mn=temp[-1]-temp[0]
    for i in range(m-n):
        res=temp[i:i+n]
        diff=res[-1]-res[0]
        if mn>diff:
            mn=diff
        
    return mn



n,m=l()
pl=l()
print(ans(pl,n,m))   