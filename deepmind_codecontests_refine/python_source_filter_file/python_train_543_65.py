t=int(input())
for i in range(t):
    n=int(input())
    tot=0
    i=0
    while (2*i+1<=n):
        tot+=4*(n-2*i-1)*(((n-1)/2)-i)
        i+=1
    print(tot)
        
    
    
