q=int(input())
l=[1,2,4,8,16,32,64,128,256,512,1024]
for i in range(q):    
    n=int(input())    
    s=[int(x) for x in input().split()]    
    
    for i in range(11):        
        while s.count(l[i])>1:            
            s.remove(l[i])            
            s.remove(l[i])            
            s.append(2*l[i])    
        if 2048 in s:        
        	print('YES')    
        else:        
        	print('NO')