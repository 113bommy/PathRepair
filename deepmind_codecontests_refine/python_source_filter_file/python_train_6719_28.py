
s=input()

k=s.split()

n=int(k[0])
se=int(k[1])-1

c=input()

cities=c.split(' ')

t=0

i=1

if cities[se-1]=='1':
    t+=1


while i<n:
    
    if se+i < n and se-i >= 0:
        
        if cities[se+i]==cities[se-i]=='1' :
            t+=2
           
        
    elif se+i < n and cities[se+i]=='1' :
        t+=1
       
        
    elif se-i >=0 and cities[se-i]=='1' :
        t+=1
    
    
    i+=1
            
    

print(t)