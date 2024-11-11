mc=0
cc=0

for _ in range(int(input())):
    
    
    m,c = map(int,input().split())
    
    if(m>c):
         mc+=1
    else:
        cc+=1
        
if(mc>cc):
    print('Mishka')
elif(cc>mc):
    print('Chris')
else:
    print('Friendship is magic!^^')   