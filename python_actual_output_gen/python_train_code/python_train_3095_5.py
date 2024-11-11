def ras(n,a):
    i=0
    a=sorted(a)
    if(a[0]==1 or a[len(a)-1]==n):
        return("NO")
    while(i<len(a)-2):
        if(a[i+1]==a[i]+1 and a[i+2]==a[i]+2):
            return('NO')
        else:
            i=i+2
    return("YES")
      
     
 

n,m=map(int,input().split())
if(m==0):
    print('NO')
else:
    a=[int(x) for x in input().split()]
    r=ras(n,a)
    print(r)
