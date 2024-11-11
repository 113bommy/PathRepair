k,n = map(int,input().split(" "))
if k%2 == 0:
    if n <= k/2:
    
        t = 1+2*(n-1)
    else:
     
        t = 2+2*(n-(k/2)-1)
else:
    if n <= int(k/2)+1:
       
        t = 1+2*(n-1)
    else:
      
        t = 2+2*(n-(int(k/2)+1)-1)
print(int(t))