ar = list(map(int, input().strip().split(' ')))
ar.sort()
#print(ar)
if ar[0]+ar[3]==ar[1]+ar[2]:
    print('YES')
elif ar[3]==ar[0]+ar[1]+ar[2]:
    print('YES')
else:
    print('NO')
    

        
    

            
        
    
        
                
            