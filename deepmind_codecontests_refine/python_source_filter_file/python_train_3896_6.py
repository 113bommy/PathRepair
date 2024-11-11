r1,c1,r2,c2=map(int,input().split())

#Rook

if(r2!=r1 and c1!=c2):
    print(2,end=" ")
else:
    print(1,end=" ")


#Bishop

MoveInOne=False

for inx in [-1,1]:
    for iny in [-1,1]:
        x=r1
        y=c1
        while(x>0 and y>0 and x<8 and y<8):
            if(x==r2 and y==c2):
                MoveInOne=True
                break
            x+=inx
            y+=iny
if((r1+c1)%2!=(r2+c2)%2):
    print(0,end=" ")
elif(MoveInOne):
    print(1,end=" ")
else:
    print(2,end=" ")

x=abs(r2-r1)
y=abs(c2-c1)

print(max(x,y))


    
