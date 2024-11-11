t=int(input())
while(t!=0):
    mini=[10]
    s=input()

    
    def calc(s, i, a, b):
        if(i+1>=mini[0]):
            return()
        if(s[i]=='1'):
            if(i%2==0):
                
                if((a+1)-b>((10-(i+1))-((10-(i+1))//2))):
                    if(i+1<mini[0]):
                        mini[0]=i+1
                    return()
                calc(s, i+1, a+1, b)
            else:
                
                if((b+1)-a>((10-(i+1))-((10-(i+1))//2))):
                    if(i+1<mini[0]):
                        mini[0]=i+1
                    return()
                calc(s, i+1, a, b+1)
                
        elif(s[i]=='0'):
            if(i%2==0):
                if(b-a>((10-(i+1))-(((10-(i+1))//2)+1))):
                    if(i+1<mini[0]):
                        mini[0]=i+1
                    return()
                calc(s, i+1, a, b)
            else:
                if(a-b>((10-(i+1))-((10-(i+1))//2))):
                    if(i+1<mini[0]):
                        mini[0]=i+1
                    return()
                calc(s, i+1, a, b)
        else:
            if(i%2==0):
                
                if((a+1)-b>((10-(i+1))-((10-(i+1))//2))):
                    if(i+1<mini[0]):
                        mini[0]=i+1
                    return()
                calc(s, i+1, a+1, b)
            else:
                
                if((b+1)-a>((10-(i+1))-((10-(i+1))//2))):
                    if(i+1<mini[0]):
                        mini[0]=i+1
                    return()
                calc(s, i+1, a, b+1)
                
            if(i%2==0):
                if(b-a>((10-(i+1))-(((10-(i+1))//2)+1))):
                    if(i+1<mini[0]):
                        mini[0]=i+1
                    return()
                calc(s, i+1, a, b)
            else:
                if(a-b>((10-(i+1))-((10-(i+1))//2))):
                    if(i+1<mini[0]):
                        mini[0]=i+1
                    return()
                calc(s, i+1, a, b)
    a=0
    b=0
    calc(s, 0, a, b)
    print(mini[0])
    t-=1
                
            
            
            
            
        
    