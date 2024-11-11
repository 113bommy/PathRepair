def check(a):
    q=0
    for i in (a[0]//2,a[0]):
        if a[0]//i==a[0]//i and a[0]%i>=i/2:
            q=1
    return q        
for i in range(int(input())):
    a = [int(x) for x in input().split()]
    if a[0]==1 and a[1]==1:
        print('YES')
    elif a[0]==1 and a[1]>1:
        print('NO')
    elif (a[1]+1)/2>a[0] and check(a)==0:
         print('NO')
    else:
        print('YES')
        
        
        
    
       
           
        
        
    