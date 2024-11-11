ar =[]
k = 0
m =0
for i in range (5):
    l =list(map(int,input().split()))
    ar.append(l)
print(ar)
for i in range(5):
    for j in range(5):
        if(int(ar[i][j])==1):
            
            
            if i!=2:
                if(i>2):
                    k = i-2
                else:
                    k  = 2-i
            if j!=2:
                if(j>2):
                    m = j-2
                else:
                    m  = 2-j
                
ans = 0
         
ans = k+m           
print(ans)
    
            
