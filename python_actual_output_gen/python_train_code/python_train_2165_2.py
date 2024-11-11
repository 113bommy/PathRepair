x=0#открыв 
y=0#закрыв
c=input()
for i in c:
    if i=='(':
        x+=1
    else:
        if x-y>0:
            x+=1
print ( 2*y )
    
