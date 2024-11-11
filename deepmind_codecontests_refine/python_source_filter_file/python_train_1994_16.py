n=int(input())
a=[int(i) for i in input().split()]
c=list(set(a))
if(len(c)==1):
    print(0)
elif(len(c)==2):
    if(abs(c[1]-c[0])%2==0):
        print(abs(c[1]-c[0])//2)
    else:
        print(abs(c[1]-c[0]))
elif(len(c)==3):
    if(abs(c[2]-c[1])==abs(c[1]-c[0])):
        print(abs(c[2]-c[1]))
    else:
        print(-1)
else:
    print(-1)
            
                
        
            
                
        
            
                
        
