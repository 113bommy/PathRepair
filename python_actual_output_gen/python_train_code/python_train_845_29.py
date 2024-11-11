r = int(input())
x=0;y=0
for i in range(1,int(r**0.5)+1):
    y = r - (i*i+i+1)
    if(y%(2*i)==0):
        y = y//(2*i)
        x = i
        break
if(x==0 or y==0):
    print("NO")
else:
    print(x,y)
