t = int(input())

for i in range(t):
    n = int(input())
    
    x = input()
    
    a  = [0 for j in range(n)]
    b  = [0 for j in range(n)]
    
    flag = -1
    for j in range(n):
        if x[j] == '1':
            
            a[j] = '1'
            b[j] = '0'  
            break
            
        elif x[j] == '2':
            a[j] = '1'
            b[j] = '1'
            
        else:
            a[j] = '0'
            b[j] = '0'
            
    #print(a,b)
    
    for k in range(j+1,n):
        if x[k] == '2':
            a[k] = '0'
            b[k] = '2'
            
        elif x[k] == '1':
            a[k] = '0'
            b[k] = '1'
            
        else:
            a[k] = '1'
            b[k] = '2'
            
    for j in range(n):
        print(a[j],end = '')
    print()
    
    for j in range(n):
        print(b[j] ,end = '')
    print()
    