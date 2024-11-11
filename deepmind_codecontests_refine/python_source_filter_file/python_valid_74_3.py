mm=int(input())

for i in range (mm) :
    aa=[]
    a,b=list(map(int,input().split()))
    n=max(a,b)
    z=(a+b)//2
    s=a+b
    if (a+b)%2==0:
        for ii in range(z+1):
            if ii+z>=n:
                aa.append(z-ii+n-ii)
    else :
        for ii in range(z+1):
            if ii+z+1>=n:
                
                aa.append(z-ii+n-ii)
        z=z+1        
        for ii in range(z+1):
            if ii+s-z>=n:
                
                aa.append(z-ii+n-ii)




    
    print(len(aa))
    print(*aa)