n,m,k = map(int ,input().split())
l = input()
l  =[int(i) for i in l.split()]

x,y = map(int , input().split())
ans,   t=2, 0 
for  i in range(1,  len(l)) :
    if i==1:
        t =  l[i]/m+(((x-l[i])**2  + y**2)**0.5)/k
    else:
        if t > l[i]/m+(((x-l[i])**2  + y**2)**0.5)/k:
            t=l[i]/m+(((x-l[i])**2  + y**2)**0.5)/k
            ans=i+1
            
print(ans)  

    
