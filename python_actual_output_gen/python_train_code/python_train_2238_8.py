n=int(input())
r=list(map(int,input().split()))
b=list(map(int,input().split()))
#print(r,b)
x=0
y=0
a=0
#5b=0
for i in range(n):
    if(r[i]==0 and b[i]==1):
        x+=1
    elif(r[i]==1 and b[i]==0):
        y+=1
    elif(r[i]==1 and b[i]==1):
        a+=1
    else:
        #b+=1
        pass
#print(x,y)
if(x<y):
    print(1)
elif(x==y or y==0):
    print(-1)
else:
    print(((x+1)//y)+((x+1)%y>0))
