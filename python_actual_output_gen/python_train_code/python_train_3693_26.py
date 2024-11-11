n=int(input())
for i in range(len(str(n))-1,-1,-1):
    x=int(str(n)[i])
    if x==0:
        print('O-|-OOOO')
    if x==1:
        print('O-|O-OOO')
    if x==2:
        print('O-|OO-OO')            
    if x==3:
        print('O-|OOO-O')                
    if x==4:
        print('O-|OOOO-')                    
    if x==5:
        print('-O|-OOOO')                        
    if x==6:
        print('O-|O-OOO')  
    if x==7:
        print('O-|OO-OO')                                
    if x==8:
        print('O-|OOO-O')            
    if x==9:
        print('O-|OOOO-')