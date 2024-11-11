t = int(input())
n,x = input().split()
x = int(x)
n = int(n)
a = [int(i) for i in input().split()]
b = [int(l) for l in input().split()][::-1]
flag=0
for j in range(n):
    if a[j]+b[j]>x:
        flag=1
        break
if flag==1:
    print("No")
else:
    print("Yes")
    
for _ in range(t-1):
    input()
    n,x = input().split()
    n = int(n)
    x = int(x)
    a = [int(i) for i in input().split()]
    b = [int(l) for l in input().split()]
    b.sort(reverse=True)
    flag = 0
    for j in range(n):
        if a[j]+b[j]>x:
            flag=1
            break
    if flag==1:
        print("No")
    else:
        print("Yes")
    
        
        
        
        
    

            
            
                
    
    
    
            
    
    
        
        
        
        
        
        
    

            
            
                
    
    
    
            
    
    