t = int(input())
for _ in range(t):
    n = int(input())
    a = 0
    b = n
    while(n>0):
        n = n -1  
        for i in range(a):
            print('()',end='')
        for j in range(b):
            print('(',end='')
        for k in range(b):
            print(')',end='') 
        print('\n')    
        a+=1 
        b=b-1
            
            