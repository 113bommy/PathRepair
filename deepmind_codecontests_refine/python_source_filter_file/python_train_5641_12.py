n=int(input())
for i in range(0,n):
    b,p,f=input().split()
    H,C=input().split()
    b=int(b)
    p=int(p)
    f=int(f)
    H=int(H)
    C=int(C)

    if b<2:
        print(0)
        continue
    if 2*p+2*f<b:
        print(p*H+f*C)
        
    if H>=C:
        
        if 2*p<=b:
            if 2*f>=(b-2*p):
                print(p*H+C*(int((b-2*p)/2)))
                continue
                

        else: 
            print(int(b/2)*H)
            continue
            
        
    if C>H:
        if 2*f<=b:
            if 2*p>=(b-2*f):
                print(f*C+H*(int((b-2*f)/2)))
                continue
            
        
        
        else:
            
            print(int(b/2)*f)
            continue

   
              
     
