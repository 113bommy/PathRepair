t=int(input())
def have_common(x,y,l,r):
    if(y<l or r<x):
        return False
    else:
        return True
for k in range(t):
    n,x,m=map(int,input().split())
    s=1
    e=0
    found=0
    for j in range(m):
        l,r=map(int,input().split())
        if(found==0 and (l<=x and x<=r)):
            found=1 
            s=l
            e=r
        elif(found==1 and have_common(s,e,l,r)):
            s=min(s,l)
            e=max(e,r)
    print(e-s+1)





            
            
        

