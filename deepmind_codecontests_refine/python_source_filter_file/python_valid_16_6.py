t=input()
z=[]
length=[]
for i in range(int(t)):
    length.append( int( input() ) )
    z.append( str(input())  )
    

print(z)
def char_req(p):
    count=0
    x=list(p)
    y=sorted(x)
    
    
    for a,b in zip(x,y):
        if a!=b:
            count+=1
            
    return count

for i in z:
    print(char_req(i))
