a,b=map(int,input().split())
c1=0
c2=0
c3=0
for i in range(1,7):
    if(abs(i-a)<abs(i-b)):
        c1=c1+1
    elif(abs(i-a)<abs(i-b)):
        c2=c2+1
    else:
        c3=c3+1
print(c1,c2,c3)
